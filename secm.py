import abc
from abc import ABC
from langpy import langpy
from autolab import autolab

class SECM():
    
    '''A class representing the Scanning electrochemical microscope'''

    def __init__(self, potentiostat_config, stepper_config):
        self.potentiostat = autolab.potentiostat(potentiostat_config)
        self.MotorController = langpy.LStepController(stepper_config)

    def FindFeedbackHeight(self,
                           MaxWay: float,
                           StepLength: float,
                           MaxSpeed: float,
                           StopCondition: float = 0.25
                           ) -> list:
        """Performs a line scan experiment along the z axis of the SECM.
        1/10 of electrode diameter is recommended as step size.
        StopCondtion is a value between 0 and 1 that represents the percentage
        change of measured current from the reference current.
         Returns the approach curve data as nested list [[position, current]].
         """
        
        #TODO: find how to set speed of the LSTEP controller

        self.MotorController.SetDistance(0, 0, -StepLength, 0)
        #self.MotorController.SetSpeed(MaxSpeed)
        way_traveled = 0
        self.potentiostat.cell_on()
        reference_current = self.potentiostat.get_actual_values()[1]
        current = reference_current
        ApproachCurve = [[way_traveled, current]]

        while abs((current-reference_current)/reference_current)<StopCondition and way_traveled < MaxWay:
            self.MotorController.MoveRelShort()
            current = self.potentiostat.get_actual_values()[1]
            way_traveled = way_traveled + StepLength
            ApproachCurve.append([way_traveled, current])
        return ApproachCurve
 
 #def MeasureApproach(self):
    #    self.MotorController.MoveRelShort()
    #    self.potentiostat.cell_on()
    #    self.potentiostat.get_actual_values()