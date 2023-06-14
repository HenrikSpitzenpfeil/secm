import os 
import keyboard
import json
import time
from langpy import langpy
from autolab import autolab
from position_storage import PositionStorage
from config.definitions import ROOT_DIR
from sdc import force_sensor, pump

#TODO: Implement dummy methods
class SECM():
    
    """A class representing the Scanning electrochemical microscope"""
#TODO: Think about the init and how to clean it up
    def __init__(self,
                 sdc: bool = True) -> None:
        
        with open(os.path.join(ROOT_DIR, "config\\secm.json")) as config:
            config  = json.load(config)
        
        #Define Constants
        #TODO: find a reasonable value
        self.stop_force = 0.05
        self.positioning_velocity = 2000

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

            self.positions = PositionStorage()
            #These only need to be defined once on startup depending on the machine and position of substrate tray.
            #How do you make this more neat? Manual setup option on init or something maybe?
            self.positions.wash = config['wash_position']
            self.positions.dip = config['dip_position']

        #self._measurement_spots = self.measurement_spots
        #self.electrode_size = 0
        #self.substrate_size = [0, 0]

    #TODO: Figure out how to best calculate measurement spots and hold substrate size
    def set_substrate_start_spot(self):
        self.manual_control()
        self.positions.substrate_start_spot = self.motor_controller.GetPos()[1:]
        
    def new_substrate(self) -> tuple:
        
        """ Prompts user to install a new substrate and move the sdc head to the new starting position.
        Returns the coordinates of the starting position"""

        input('Please install a new substrate')
        self.substrate_size = list(input('Please input a list with substrate size'))
        print('Please use W, A, S, D, +, - to move Probe to starting position for calibration. Press q to confirm')
        self.manual_control() #enables manual control of the probe
        print('Substrate calibrated successfully')
        return self.motor_controller.GetPos()[1:]

    def find_contact(self,
                     MaxWay: float,
                     StepLength: float,
                     StopCondition: float) -> list:
        
        """Moves the arm towards the substrate until 
        a force threshold is exceeded at the sdc head.
        1/10 of electrode diameter is recommended as step size.
        StopCondtion is a force value measured by 
        the force sensor of the sdc head. 200 mN ≈ 0,22"""

        way_traveled = 0
        move_duration = StepLength/self.positioning_velocity

        while way_traveled < MaxWay:
            self.motor_controller.MoveRelSingleAxis(3, -StepLength, False)
            t_end = time.time() + move_duration
            while time.time() < t_end:
                if self.get_force_sensor_value() >= StopCondition:
                    return print("Contact found")
            way_traveled = way_traveled + StepLength
        return print("No contact found")
    
    #TODO: Implement this as a function of electrode size and substrate size
    def move_to_next_experiment(self, step_size, max_x, max_y):
        
        """ Moves the sdc head to the next measurement spot.
        Includes logic to find if there is no space left on substrate"""
        
        # Find the distance already traveled in x and y directions
        x_traveled = self.positions.substrate_start_spot[0] - self.positions.current_position[0]
        y_traveled = self.positions.substrate_start_spot[1] - self.positions.current_position[1]

        if x_traveled > max_x - step_size: # Check if there is no space left in x-direction
            
            if y_traveled > max_y-step_size: # Check if there is no space left in y-direction
                self.new_substrate() # Out of space on substrate new substrate needs to be installed
            
            else: # Out of x-space move to new line in y-axis
                self.motor_controller.MoveRelSingleAxis(2, - step_size)
                self.motor_controller.MoveAbsSingleAxis(1, self.positions.substrate_start_spot()[0]) 
                self.positions.current_position = self.motor_controller.GetPos[1:]
        
        else: # Space in x-direction left move to next spot
            self.motor_controller.MoveRelSingleAxis(1, - step_size)
            self.positions.current_position = self.motor_controller.GetPos[1:]
    
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

    def prepare_next_experiment(self) -> None:
        
        """Aspirate the sdc head find next contact position
          and primes cell for next experiment"""
        
        self.microdose_pump.set_program(30, 100, 0) # pulls electrolyte back into sdc head
        self.microdose_pump.run_pump()
        self.motor_controller.MoveRelSingleAxis(3, 1000, True) #lift sdc head
        #self.move_to_next_spot()
        self.find_contact(1500, 20, 0.22)
        contact_position = self.motor_controller.GetPos() # Find the next position without elctrolyte in the sdc head
        self.prime_cell()  # prime cell with electrolyte
        self.motor_controller.MoveAbs(contact_position[1],
                                      contact_position[2],
                                      contact_position[3],
                                      contact_position[4])
        self.find_contact(1500, 20, 0.22) # make sure adequate contact is sustained 

    def get_force_sensor_value(self) -> float:
        
        """Get the current value of the force sensor"""

        return self.force_sensor.get_measurement().value

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
