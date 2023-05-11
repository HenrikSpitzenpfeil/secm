import abc
from abc import ABC
from langpy import langpy
from autolab import autolab

class SECM():
    
    '''A class representing the physical Scanning electrochemical microscope'''

    def __init__ (self, potentiostat_config, stepper_config):
        self.potentiostat = autolab.potentiostat(potentiostat_config)

class AbstractExperiment(ABC):
 '''creation pattern for different experiments.
 TODO: decide if this needs to be it's own thing ontop of SECM'''
    
    @abc.abstractmethod
    def execute(self):
        ...