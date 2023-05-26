from dataclasses import dataclass

@dataclass
class PositionStorage:
    
    _dip: list[float]
    _wash: list[float]
    _substrate_initial_position: list[float]
        
    @property
    def wash(self) -> list:
        return self._wash
    
    @wash.setter
    def wash(self, coordinates: list) -> None:
        coordinates = self.validate_coordinates(coordinates)
        self._wash = coordinates
    
    @property
    def dip(self) -> list:
        return self._dip
    
    @dip.setter
    def dip(self, coordinates: list) -> None:
        #coordinates = self.validate_coordinates(coordinates)
        self._dip = self.validate_coordinates(coordinates)

    @property
    def substrate_initial_spot(self) -> list:
        return self._substrate_initial_position
    
    @substrate_initial_spot.setter
    def substrate_initial_spot(self, coordinates: list) -> None:
        coordinates = self.validate_coordinates(coordinates)
        self._substrate_initial_position = coordinates

    def validate_coordinates(self, coordinates):
        if not len(coordinates) == 4:
            raise ValueError('Invalid amount of coordinates given')
        if not type(coordinates) == list:
            raise ValueError('Invalid Data Type')
        return coordinates