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
        self.electrode_size = 0
        self.substrate_size = [0, 0]

    #TODO: Figure out how to best calculate measurement spots and hold substrate size
    #@property
    #def measurement_spots(self) -> int:
    #    return self._measurement_spots
    
    #@measurement_spots.setter
    #def measurement_spots(self, amount: int) -> None:
    #    ...

    def total_measurement_spots(self) -> int:
        ...
    
    def measurements_left(self) -> int:
        ...
    
    def next_substrate(self):
       # input('Please install a new substrate')
       # self.substrate_size = list(input('Please input a list with substrate size'))
       # print('Please use arrow keys to move Probe to starting position for calibration')
       # while True:
       #     if enter == True:
       #      break
       #     self.enable_manual_move
       # self.find_feedback_height()
       # print('Substrate calibrated successfully')
       ...

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
    def move_to_next_experiment(self):
        ...
    
    def move_to_wash(self):
        self.motor_controller.MoveAbs(*self.positions.wash)
    
    def move_to_dip(self):
        self.motor_controller.MoveAbs(*self.positions.dip)
    
    # TODO: read sdc manual
    def wash_cell(self):
        self.microdose_pump.set_program(100, )
    
    def make_droplet(self):
        ...
    
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
