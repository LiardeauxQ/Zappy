from AI.sources.socket.socket import *
from AI.sources.ressources.dictionaries import *

class Player:

    def __init__(self):
        self.client = SocketZappy()
        self.client.connect_zappy()
        self.level = 1
        self.food = 10
        self.linemate = 0
        self.deraumere = 0
        self.sibur = 0
        self.mendiane = 0
        self.phiras= 0
        self.thystame = 0

    def forward(self):
        self.client.sendMessage("Forward\n")

    def right(self):
        self.client.sendMessage("Right\n")

    def left(self):
        self.client.sendMessage("Left\n")

    def look(self):
        l = self.client.sendMessage("Look\n")
        print(l)

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
        if self.food > 10:
            return True
        else:
            return False

    def checkElevation(self):
        if self.linemate >= CONSTANTS["linemate_necessary"][self.level] and\
        self.deraumere >= CONSTANTS["deraumere_necessary"][self.level] and\
        self.sibur >= CONSTANTS["sibur_necessary"][self.level] and\
        self.mendiane >= CONSTANTS["mendiane_necessary"][self.level] and\
        self.phiras >= CONSTANTS["phiras_necessary"][self.level] and\
        self.thystame >= CONSTANTS["thystame_necessary"][self.level]:
            return True
        else:
            return False

    def checkRessource(self, name):
        if vars(self)[name] >= name + '_deseriable'[self.level]:
            return True
        else:
            return False

    def checkLook(self, array):
        for i, elems in enumerate(array):
            for elem in elems:
                if self.checkRessource(elem):
                    self.actions = CONSTANTS["move_to_case"][i]
                    self.handleActions()
                    self.takeObject(elem)
                    return
        self.forward()

    def handleActions(self):
        while len(self.actions) > 0:
            action = self.actions.pop(0)
            if action == "Left":
                self.left()
            elif action == "Right":
                self.right()
            else:
                self.forward()

    def dropItemsForElevation(self):
        for _ in range(CONSTANTS["linemate_necessary"][self.level]):
            self.dropObject("linemate")
        for _ in range(CONSTANTS["deraumere_necessary"][self.level]):
            self.dropObject("deraumere")
        for _ in range(CONSTANTS["sibur_necessary"][self.level]):
            self.dropObject("sibur")
        for _ in range(CONSTANTS["mendiane_necessary"][self.level]):
            self.dropObject("mendiane")
        for _ in range(CONSTANTS["phiras_necessary"][self.level]):
            self.dropObject("phiras")
        for _ in range(CONSTANTS["thystame_necessary"][self.level]):
            self.dropObject("thystame")

    def moveToElevation(self, tile):
        if tile == 0:
            return
        self.actions = CONSTANTS["move_to_sound"][tile]
        self.handleActions()
        # newtile = self.broadcast text
            # self.moveToElevation(newtile)
        # wait to know which text in broadcast to send 