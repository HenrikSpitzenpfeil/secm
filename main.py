import os 
import keyboard
import json
import time
from langpy import langpy
from autolab import autolab
from position_storage import PositionStorage
from config.definitions import ROOT_DIR
from sdc import force_sensor, pump

class SECM():
    
    """A class representing the Scanning electrochemical microscope"""
#TODO: Think about the init and how to clean it up
    def __init__(self,
                 sdc: bool = True) -> None:
        
        """Adjust settings in the secm.json config file according to needs and
        system requirements (i.e changed different COM Port)"""

        with open(os.path.join(ROOT_DIR, "config\\secm.json")) as config:
            config  = json.load(config)
        
        #Define Constants
        #TODO: find a reasonable value
        self.positions = PositionStorage()
        self.stop_force = config['emergency_stop_force'] # This is the force at which move commands during manual control are interrupted
        self.contact_force = config['contact_force'] # This is the force used to find contact with the substrate
        self.positioning_velocity = config['positioning_velocity']

        #Initialize Motor Controller and set parameters
        self.motor_controller = langpy.LStepController(os.path.join(ROOT_DIR,
                                                                    config['stepper_dll']))
        self.motor_controller.SetVel(self.positioning_velocity,
                                     self.positioning_velocity,
                                     self.positioning_velocity,
                                     0)
        
        #If scanning droplet cell is enabled initialize it
        if sdc == True:
            #Port configuration for the Palkovits SECM
            self.force_sensor = force_sensor.MEGSV_3(os.path.join(ROOT_DIR,
                                                                  config['force_sensor_dll']),
                                                     config['force_sensor_port'],
                                                     config['force_sensor_buffer_size'])
            
            self.microdose_pump = pump.MicrodosePump(config['pump_port'],
                                                     config['pump_baudrate'],
                                                     config['pump_timeout'])

            #These only need to be defined once on startup depending on the machine and position of substrate tray.
            #How do you make this more neat? Manual setup option on init or something maybe?
            self.positions.wash = config['wash_position']
            self.positions.dip = config['dip_position']

        self.electrode_size = config['electrode_size']
        self.substrate_size: list[float] = [None, None]
        self.xy_axis_length = config['xy_axis_length']
        self.max_travel = config['xy_axis_length']

    # TODO: Figure out how to best calculate measurement spots and hold substrate size
    def set_substrate_start_spot(self):
        print('Please use W, A, S, D, +, - to move Probe to starting position for calibration. Press q to confirm')
        self.manual_control()
        self.positions.substrate_start_spot = list(self.motor_controller.GetPos()[1:])

    # TODO: Add MaxTravel calculation and figure out the other TODO
    def new_substrate(self) -> tuple:
        
        """ Prompts user to install a new substrate and move the sdc head to the new starting position.
        Returns the coordinates of the starting position"""

        input('Please install a new substrate')
        self.substrate_size[0] = float(input('Please input x length of the substrate'))
        self.substrate_size[1] = float(input('Please input y length of the substrate'))
        self.set_substrate_start_spot() #enables manual control of the probe
        self.set_max_travel()
        self.positions.current_position = list(self.motor_controller.GetPos()[1:])
        self.find_contact(5000, 50, self.contact_force)
        contact_position = self.motor_controller.GetPos()[1:] # Find the next position without electrolyte in the sdc head
        time.sleep(0.1)
        self.prime_cell()  # prime cell with electrolyte
       
       # TODO: Shitty implementation needs fixing
        for coordinates in range(3): # Move the head to contact position axis by axis to prevent scraping
            self.motor_controller.MoveRelSingleAxis(coordinates, contact_position[coordinates])
        
        self.find_contact(5000, 50, self.contact_force) # make sure adequate contact is sustained
        print('Substrate calibrated successfully, ready for measurement')
    
    def prepare_next_experiment(self, step_size) -> None:
            
            """Aspirate the sdc head find next contact position
            and primes cell for next experiment"""
            
            self.microdose_pump.set_program(30, 100, 0) # pulls electrolyte back into sdc head
            self.microdose_pump.run_pump()
            self.motor_controller.MoveRelSingleAxis(3, 1000, True) #lift sdc head
            self.move_to_next_experiment(step_size)
            self.find_contact(5000, 50, self.contact_force)
            contact_position = self.motor_controller.GetPos()[1:] # Find the next position without electrolyte in the sdc head
            time.sleep(0.1)
            self.prime_cell()  # prime cell with electrolyte
            
            # TODO: Shitty implementation needs fixing
            for coordinates in range(3): # Move the head to contact position axis by axis to prevent scraping
                self.motor_controller.MoveRelSingleAxis(coordinates, contact_position[coordinates])

            self.find_contact(5000, 50, self.contact_force) # make sure adequate contact is sustained

    def find_contact(self,
                     MaxWay: float,
                     StepLength: float,
                     StopCondition: float) -> list:
        
        """Moves the arm towards the substrate until 
        a force threshold is exceeded at the sdc head.
        1/10 of electrode diameter is recommended as step size.
        StopCondtion is a force value measured by 
        the force sensor of the sdc head. 200 mN ≈ 0,022"""

        way_traveled = 0
        move_duration = StepLength/self.positioning_velocity

        while way_traveled < MaxWay:
            self.motor_controller.MoveRelSingleAxis(3, -StepLength, False)
            t_end = time.time() + move_duration
            
            while time.time() < t_end: #check force sensor during move command 
                if self.get_force_sensor_value() >= StopCondition:
                    return print("Contact found")
            way_traveled = way_traveled + StepLength #track distance moved 
        return print("No contact found")
    
    def move_to_next_experiment(self, step_size):
        
        """ Moves the sdc head to the next measurement spot.
        Includes logic to find if there is no space left on substrate"""
        
        # Find the distance already traveled in x and y directions
        x_traveled = self.positions.substrate_start_spot[0] - self.positions.current_position[0]
        y_traveled = self.positions.substrate_start_spot[1] - self.positions.current_position[1]

        if x_traveled > self.max_travel[0] - step_size: # Check if there is no space left in x-direction
            
            if y_traveled > self.max_travel[1] - step_size: # Check if there is no space left in y-direction
                self.new_substrate() # Out of space on substrate new substrate needs to be installed
            
            else: # Out of x-space move to new line in y-axis
                self.motor_controller.MoveRelSingleAxis(2, -step_size)
                self.motor_controller.MoveAbsSingleAxis(1, self.positions.substrate_start_spot[0]) 
                self.positions.current_position = list(self.motor_controller.GetPos()[1:])
        
        else: # Space in x-direction left move to next spot
            self.motor_controller.MoveRelSingleAxis(1, -step_size)
            self.positions.current_position = list(self.motor_controller.GetPos()[1:])
    
    def move_to_wash(self):
        self.motor_controller.MoveAbs(*self.positions.wash)
    
    def move_to_dip(self):
        self.motor_controller.MoveAbs(*self.positions.dip)
    
    def prime_cell(self) -> None:
        
        """Flushes the cell of used electrolyte and removes excess electrolyte"""

        self.move_to_wash()
        self.microdose_pump.set_program(30, 150, 1)
        self.microdose_pump.run_pump() # flushes the cell
        self.move_to_dip() # removes excess
        self.motor_controller.MoveRelSingleAxis(3, 1000, True) # lift up to break surface tension

    def get_force_sensor_value(self) -> float:
        
        """Get the current value of the force sensor"""

        return self.force_sensor.get_measurement().value

    # TODO: think about how to reserve some margin and account for already used axis space because of wash etc.
    def set_max_travel(self) -> None:
        
        """ Calcualate and set the maximum travel of the head
        to stay on the substrate and not exceed the maximum travel of the axis"""

        current_xy = self.motor_controller.GetPos()[1:3] # Get the current x, y coordinates of the sdc head
        axis_length_used = []
        
        for i in range(len(self.xy_axis_length)):
            axis_length_used.append(self.xy_axis_length[i]-current_xy[i]) # Calculate the axis length already used
        
        for i in range(len(self.substrate_size)): # find if the substrate or axis length is limiting for x and y direction
            if self.substrate_size[i] + axis_length_used[i] < self.xy_axis_length[i]:
                self.max_travel[i] = self.substrate_size[i] - 200 # Reserve some margin so not to measure right at the edge of the substrate
            else:
                self.max_travel[i] = self.xy_axis_length[i]-axis_length_used[i]
    
    def manual_control(self) -> None:
        
        """Enables manual control of the SECM X,Y,Z arm.
        Controls are WASD for X,Y and +,- for Z axis"""

        keyboard.on_press(self._handle_key_press)
        keyboard.on_release(self._handle_key_release)
        
        while True:
            if keyboard.is_pressed('q'):
                keyboard.unhook_all()
                break  # Exit the manual control loop
            if self.get_force_sensor_value() >= self.stop_force:
                self.motor_controller.StopAxes()
                keyboard.unhook_all()
                break
            time.sleep(0.001)
        keyboard.unhook_all()
    
    def _handle_key_press(self, event) -> None:
        """Helper functions for the manual control.
        Defines the hotkeys and the move distance per button press."""

        key = event.name
        move_distance = 1000
        sleep_time = 0.6
        #Magic numbers are distance moved per key press 
        if key == 'w':
            self.motor_controller.MoveRelSingleAxis(2, move_distance, False)
            time.sleep(sleep_time)
        elif key == 's':
            self.motor_controller.MoveRelSingleAxis(2, -move_distance, False)
            time.sleep(sleep_time)
        elif key == 'a':
            self.motor_controller.MoveRelSingleAxis(1, -move_distance, False)
            time.sleep(sleep_time)
        elif key == 'd':
            self.motor_controller.MoveRelSingleAxis(1, move_distance, False)
            time.sleep(sleep_time)
        elif key == '+':
            self.motor_controller.MoveRelSingleAxis(3, move_distance, False)
            time.sleep(sleep_time)
        elif key == '-':
            self.motor_controller.MoveRelSingleAxis(3, -move_distance, False)
            time.sleep(sleep_time)

    def _handle_key_release(self, event) -> None:
        """ Helper function to handle the key release. 
        Currently nothing happens on key release"""
        
        pass
