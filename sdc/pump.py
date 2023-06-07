import serial
import json
import os
import re
import time
from config.definitions import ROOT_DIR
class MicrodosePump:
    """Class for the Microdose PCON-C Pump that is used to move elctrolyte to 
    and from the SDC Head"""
    def __init__(self, config: dict) -> None:
        try:
            self.pump =  serial.Serial(config['port'],
                                   config['baudrate'],
                                   config['timeout'])
            print("Connected to Microdose Pump")
        except:
            print("Failed to connect to Microdose Pump")
        
        self.handshake_regex = re.compile("HS\,.+")
    
    def set_program(self,
                    flowrate: int,
                    volume: int,
                    direction: int = 1
                    ) -> None:
        
        """Set the Pump program which will be executed when run_pump is called.
        Direction is 0 to pump to the SDC Head, 1 to pump away."""

        self.pump.write(bytes('1,WPU,1,0,0,1.0\r','utf-8'))
        self.pump.write(bytes('1,WPI,1,1,1,1,Default\r','utf-8'))
        self.pump.write(bytes('1,WVT,1,1,0,{},Dispense\r'.format(volume),'utf-8'))
        self.pump.write(bytes('1,WFR,1,1,{},{},{}\r'.format(flowrate,
                                                           flowrate,
                                                           direction),'utf-8'))
        self.ser.write(bytes('1,WSC,1,1,0,0\r','utf-8'))
        return None
    
    def run_pump(self) -> None:
        """Executes the Program set with set_program"""
        self.pump.write(bytes('1,EP,1\r','utf-8'))

        self.ensure_pump_status_ready() # ensures that pump program has completed
        return None

    def ensure_pump_status_ready(self) -> None:
        while True:
            pump_status = self.get_pump_status
            if pump_status == 1:
                break
            time.sleep(0.1)
    
    def get_pump_status(self) -> int:
        """Get the pump status code from the handshake. 
        Returns intiger status code."""
        
        self.pump.write(bytes('1,RSS,0\r', 'utf-8'))
        answer = self.pump.read(100)
        handshake = re.search(self.handshake_regex, answer.decode())
        return handshake[6]

    def read_pump(self) -> str:
        return self.pump.read(1000)