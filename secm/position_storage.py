from dataclasses import dataclass, field

@dataclass
class PositionStorage:

    """Class to store positons of the sdc/secm setup.
    Coordinate have the shape [X, Y, Z, A]"""

    _dip: list[float] = field(default_factory=list)
    _wash: list[float] = field(default_factory=list)
    _substrate_start_spot: list[float] = field(default_factory=list)
    _current_position: list[float] = field(default_factory=list)
        
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
        coordinates = self.validate_coordinates(coordinates)
        self._dip = coordinates

    @property
    def substrate_start_spot(self) -> list:
        return self._substrate_start_spot
    
    @substrate_start_spot.setter
    def substrate_start_spot(self, coordinates: list) -> None:
        coordinates = self.validate_coordinates(coordinates)
        self._substrate_start_spot = coordinates

    @property
    def current_position(self) -> list:
        return self._current_position
    
    @current_position.setter
    def current_position(self, coordinates: list) -> None:
        coordinates = self.validate_coordinates(coordinates)
        self._current_position = coordinates

    def validate_coordinates(self, coordinates):
        
        """Ensures that coordinate passed are valid and have shape [X,Y,Z,A]"""
        
        if not len(coordinates) == 4:
            raise ValueError('Invalid amount of coordinates given')
        if not type(coordinates) == list:
            raise ValueError('Invalid Data Type')
        return coordinates
    
    def set_coordinates(self, attribute: str, coordinates: list[float]) -> None:
        coordinates = self.validate_coordinates(coordinates)
        setattr(self, attribute, coordinates)