from enum import Enum

class StonesTypes(Enum):
    UNKNOW = 0
    LINEMATE = 1
    DERAUMERE = 2
    SIBUR = 3
    MENDIANE = 4
    PHIRAS = 5
    THYSTAME = 6

    def describe(self):
        return self.name