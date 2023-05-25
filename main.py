import abc
from abc import ABC
from langpy import langpy
from autolab import autolab

#TODO: Implement dummy methods
class SECM():
    
    '''A class representing the Scanning electrochemical microscope'''

    def __init__(self, potentiostat_config, stepper_config):
        self.potentiostat = autolab.potentiostat(potentiostat_config)
        self.motor_controller = langpy.LStepController(stepper_config)
        self._measurement_spots = self.measurement_spots
        self._wash_position = self.wash_position
        self._dip_position = self.dip_position
        self._substrate_initial_spot = self.substrate_initial_spot
        self.electrode_size = 0
        self.substrate_size = [0, 0]

    #TODO: Figure out how to best calculate measurement spots and hold substrate size
    @property
    def measurement_spots(self) -> int:
        return self._measurement_spots
    
    @measurement_spots.setter
    def measurement_spots(self, amount: int) -> None:
        ...

    @property
    def wash_position(self) -> int:
        return self._wash_position
    
    @wash_position.setter
    def wash_position(self, amount: int) -> None:
        ...
    
    @property
    def dip_position(self) -> int:
        return self._dip_position
    
    @dip_position.setter
    def dip_position(self, amount: int) -> None:
        ...

    @property
    def substrate_initial_spot(self) -> int:
        return self._measurement_spots
    
    @substrate_initial_spot.setter
    def substrate_initial_spot(self, amount: int) -> None:
        ...

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
        self.motor_controller.MoveAbs(*self.wash_position)
    
    def move_to_dip(self):
        self.motor_controller.MoveAbs(*self.dip_position)
    
    def flush_cell(self):
        ...
    
    def make_droplet(self):
        ...