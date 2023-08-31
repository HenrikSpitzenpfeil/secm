import serial
import re
import time


class MicrodosePump:

    """Class for the Microdose PCON-C Pump that is used to move elctrolyte to 
    and from the SDC Head"""

    def __init__(self, port: str, baudrate: int, timeout: int) -> None:
        try:
            self.pump = serial.Serial(port, baudrate, timeout = timeout)
            print("Connected to Microdose Pump")
        except:
            print("Could not open pump serial port")
        
        # Matches the handshake status pattern of the pump
        self.handshake_regex = re.compile("\d,HS\,[A-Z]{2}(?:\,\d)+")
    
    def open_port(self) -> None:
        try:
            self.pump.open()
        except:
            print("Could not oper pump serial port")

    def close_port(self) -> None:
        self.pump.close()

    def set_program(self,
                    flowrate: int,
                    volume: int,
                    direction: int = 1
                    ) -> None:
        
        """Set the Pump program which will be executed when run_pump is called.
        Direction is 1 to pump to the SDC Head, 0 to pump away."""

        # Set the pump units to mikrolitre
        self.pump.write(bytes('1,WPU,1,0,0,1.0\r','utf-8'))
        # Set program information to 1 cycle, 1 step, and program name
        self.pump.write(bytes('1,WPI,1,1,1,1,Default\r','utf-8'))
        # Set pump to volume control and volume to be moved
        self.pump.write(bytes('1,WVT,1,1,0,{},Dispense\r'.format(volume),'utf-8'))
        # Set the flowrate and direction of the program
        self.pump.write(bytes('1,WFR,1,1,{},{},{}\r'.format(flowrate,
                                                           flowrate,
                                                           direction),'utf-8'))
        # Set the start signal to run the program immediately upon execution
        self.pump.write(bytes('1,WSC,1,1,0,0\r','utf-8'))
        return None
    
    def run_pump(self) -> None:
        
        """Executes the Program set with set_program"""

        self.pump.write(bytes('1,EP,1\r','utf-8'))

        self.ensure_pump_status_ready() # ensures that pump program has completed
        return None

    def ensure_pump_status_ready(self) -> bool:
        
        """ Ensures that pump program has completed
          and the pump is available to receive commands."""
        
        while True:
            handshake = self.get_pump_status()
            if handshake == None: # For some reason get_pump_status can return None even though it shouldn't be able to
                continue

            pump_status = int(handshake[8])
            if pump_status == 1: # Pump status 1 is  pump in command mode available to receive commands
                return True
            time.sleep(0.1)
    
    def get_pump_status(self) -> str:
        
        """Get the pump status code from the handshake. 
        Returns intiger status code."""
        
        self.pump.write(bytes('1,RSS,0\r', 'utf-8')) # command to ask for the pump status
        answer = self.read_pump()
        
        # iterate over the list of pump outputs to find the handshake with pump status information
        for i in answer:
            match = re.search(self.handshake_regex, i)
            if match != None:
                return match.group()
        if match == None:
            self.get_pump_status()

    def read_pump(self) -> list:
        
        """ Reads the COM Buffer and returns a list of strings."""
        
        out = self.pump.read(1000) 
        out = out.decode() # Turns bytes into strings
        return out.split('\r')
