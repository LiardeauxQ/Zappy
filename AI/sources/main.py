from sources.ressources.stone import *
from sources.ressources.stonesTypes import *
from sources.ressources.dictionaries import *

if __name__ == "__main__":
    s = Stone(StonesTypes.LINEMATE)
    
    s.logStone()
    print("LINEMATE desirable at level 1 =", level_1_desirable[StonesTypes.LINEMATE])
