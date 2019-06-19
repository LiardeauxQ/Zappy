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

    def takeObject(self, elem):
        self.client.sendMessage("Take " + elem + "\n")

    def dropObject(self, elem):
        self.client.sendMessage("Set " + elem + "\n")

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

    def checkLook(self, array):
        for i, elems in enumerate(array):
            for elem in elems:
                if self.checkRessource(elem):
                    self.actions = move_to_case[i]
                    self.handleActions(elem)
                    return
        self.forward()

    def handleActions(self, elem):
        while len(self.actions) > 0:
            action = self.actions.pop(0)
            if action == "Left":
                self.left()
            elif action == "Right":
                self.right()
            else:
                self.forward()
        self.takeObject(elem)
