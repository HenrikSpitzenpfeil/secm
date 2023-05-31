import ctypes

#TODO: add unit converter to mN
class MEGSV_3:
    
    def __init__(self, dll_path, port, buffer_size):
        self.dll = ctypes.WinDLL(dll_path)
        self.port = ctypes.c_int(port)
        self.buffer_size = ctypes.c_int(buffer_size)
        self.dll.GSVactivate(self.port, self.buffer_size)

    def get_measurement(self):
        value = ctypes.c_double()
        dll.GSVRead(self.port, ctypes.byref(value))
        return value
    
    def release(self):
        self.dll.GSVrelease(self.port,self.buffer) 