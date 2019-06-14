
# First import the files like this

from sources.ressources.stone import *
from sources.ressources.stonesTypes import *
from sources.ressources.dictionaries import *
from sources.elevation.playerNeededForElevation import *


def exemple():
    # creation of an obsject s with class Stone
    # Usage: obj = Stone(StonesTypes.STONE) by default stone type is unknow.

    s = Stone(StonesTypes.LINEMATE)
    
    # logStone print stone type

    s.logStone()

    # You can get the number of ressources required by using dictionaries 
    # Usage : nameofthestone_{desirable|necessary}[level] you get an int

    print(StonesTypes.LINEMATE, "desirable From level 5 to level 6  =", linemate_desirable[5])

    # You can get the number of player necessary for an elevation by calling  playerNeededForElevation dictionary
    # Usage:  playerNeededForElevation[level]
    print("From level 2 to level 3 you need", playerNeededForElevation[2], "players")


if __name__ == "__main__":
    exemple()