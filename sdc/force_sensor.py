import ctypes

#TODO: add unit converter to mN
class MEGSV_3:
    
    def __init__(self, dll_path: str, port: int, buffer_size: int) -> None:
        self.dll = ctypes.WinDLL(dll_path)
        self.port = ctypes.c_int(port)
        self.buffer_size = ctypes.c_int(buffer_size)
        self.dll.GSVactivate(self.port, self.buffer_size)

    def get_measurement(self) -> ctypes.c_double:
        value = ctypes.c_double()
        self.dll.GSVread(self.port, ctypes.byref(value))
        return value
    
    def release(self) -> None:
        self.dll.GSVrelease(self.port,self.buffer) 