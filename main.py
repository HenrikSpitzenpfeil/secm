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
        
        #Definie Constants
        #TODO: find a reasonable value
        self.stopforce = 100000
        self.positioning_velocity = 2000

        #self.potentiostat = autolab.potentiostat(config['potentiostat_config'])

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

    #TODO: Implement force sensor of sdc. Async for contact?
    def find_contact(self,
                           MaxWay: float,
                           StepLength: float,
                           StopCondition: float = 0.25
                           ) -> list:
        '''Performs a line scan experiment along the z axis of the SECM.
        1/10 of electrode diameter is recommended as step size.
        StopCondtion is a value between 0 and 1 that represents the percentage 
        change of measured current from the reference current.
         Returns the approach curve data as nested list [[position, current]].
         '''
        
        #TODO: find how to set speed of the LSTEP controller

        self.motor_controller.SetDistance(0, 0, -StepLength, 0)
        #self.MotorController.SetSpeed(MaxSpeed)
        way_traveled = 0
        self.potentiostat.cell_on()
        reference_current = self.potentiostat.get_actual_values()[1]
        current = reference_current
        ApproachCurve = [[way_traveled, current]]

        while abs((current-reference_current)/reference_current) < StopCondition and way_traveled < MaxWay:
            self.motor_controller.MoveRelShort()
            current = self.potentiostat.get_actual_values()[1]
            way_traveled = way_traveled + StepLength
            ApproachCurve.append([way_traveled, current])
        return ApproachCurve
    
    #TODO: Implement this as a function of electrode size and substrate size
    def move_to_next_experiment(self):
        ...
    
    def move_to_wash(self):
        self.motor_controller.MoveAbs(*self.positions.wash)
    
    def move_to_dip(self):
        self.motor_controller.MoveAbs(*self.positions.dip)
    
    def flush_cell(self):
        ...
    
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
                break  # Exit the manual control loop
            if self.get_force_sensor_value() == self.stopforce:
                break
    
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
