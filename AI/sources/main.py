from sources.ressources.stone import *
from sources.ressources.stonesTypes import *
from sources.ressources.dictionaries import *
from sources.elevation.playerNeededForElevation import *


if __name__ == "__main__":
    s = Stone(StonesTypes.LINEMATE)
    
    s.logStone()
    print("LINEMATE desirable at level 1 =", level_1_desirable[StonesTypes.LINEMATE])
    print("From level 2 to level 3 you need", playerNeededForElevation[2], "players")
