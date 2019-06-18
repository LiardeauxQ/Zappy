from sources.socket.socket import *
from sources.ressources.dictionaries import *

class Player:

    def __init__(self):
        self.client = Socket()
        self.level = 1
        self.linemate = 0
        self.deraumere = 0
        self.sibur = 0
        self.mendiane = 0
        self.phiras= 0
        self.thystame = 0
        self.linemate_necessary = linemate_necessary

    def forward(self):
        self.client.sendMessage("Forward\n")

    def right(self):
        self.client.sendMessage("Right\n")

    def left(self):
        self.client.sendMessage("Left\n")

    def look(self):
        self.client.sendMessage("Look\n")

    def inventory(self):
        self.client.sendMessage("Inventory\n")

    def broadcast(self):
        self.client.sendMessage("Broadcast text\n")
        return self.client.getData()

    def connectNumber(self):
        self.client.sendMessage("Connect_nbr\n")

    def fork(self):
        self.client.sendMessage("Fork\n")

    def eject(self):
        self.client.sendMessage("Eject\n")

    def takeObject(self):
        self.client.sendMessage("Take object\n")

    def dropObject(self):
        self.client.sendMessage("Set object\n")

    def startIncantation(self):
        self.client.sendMessage("Incantation\n")

    def checkFood(self):
        if self.life / 126 > 8:
            return True
        else:
            return False

    def checkElevation(self):
        if self.linemate >= linemate_necessary[self.level] and\
        self.deraumere >= deraumere_necessary[self.level] and\
        self.sibur >= sibur_necessary[self.level] and\
        self.mendiane >= mendiane_necessary[self.level] and\
        self.phiras >= phiras_necessary[self.level] and\
        self.thystame >= thystame_necessary[self.level]:
            return True
        else:
            return False

    def checkRessource(self, name):
        # replace 'neceassry' by 'desirable'
        if vars(self)[name] >= vars(self)[(name + '_necessary')][self.level]:
            return True
        else:
            return False