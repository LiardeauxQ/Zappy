from sources.ressources.stonesTypes import *


class Stone:

    def __init__(self, type = StonesTypes.UNKNOW):
        self.type = type

    def change_type(self, new_type):
        self.type = new_type
    
    def logStone(self):
        print("Stone is of type :", self.type.describe())