from AI.sources.socket.socket import *
from AI.sources.ressources.dictionaries import *
import sys

class Player:

    def __init__(self, port = 6000, team = "test_team", host = "localhost"):
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
        self.port = port
        self.host = host
        self.team = team
  

    def forward(self):
        self.client.sendMessage("Forward\n")

    def right(self):
        self.client.sendMessage("Right\n")

    def left(self):
        self.client.sendMessage("Left\n")

    def look(self):
        l = self.client.sendMessage("Look\n")
        l = self. __parseLookString(l)
        self.checkLook(l)
        print(l)

    def inventory(self):
        l = self.client.sendMessage("Inventory\n")          
        print(l)
        self.__parseInventoryString(l)

    def __parseInventoryString(self, array):
        array = array.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "")
        result = array.split(',')
        for i in range(len(result)):
            result[i] = result[i].strip().split(' ')
        for i in range(len(result)):
            vars(self)[result[i][0]] = int(result[i][1]);
        print (result)
        return result

        

    def broadcast(self, text):
        self.client.sendMessage("Broadcast " + text + "\n")

    def connectNumber(self):
        res = self.client.sendMessage("Connect_nbr\n")
        res = res[:-1]
        return int(res)

    def fork(self):
        tmp = self.connectNumber()
        if tmp > 0:
            self.client.sendMessage("Fork\n")

    def eject(self):
        self.client.sendMessage("Eject\n")

    def takeObject(self, elem):
        self.client.sendMessage("Take " + elem + "\n")
        vars(self)[elem] += 1

    def dropObject(self, elem):
        self.client.sendMessage("Set " + elem + "\n")

    def startIncantation(self):
        self.client.sendMessage("Incantation\n")

    def checkFood(self):
        if self.food > 10:
            return True
        else:
            return False

    def __parseBroadcast(self, message):
        message = message.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "").replace(",", "")
        result = message.split(" ")
        print(result)
        return int(result[1])




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
        # replace 'neceassry' by 'desirable'
        if name == "player" or name == "food" or name == "":
            return False
        if vars(self)[name] < CONSTANTS[name + "_necessary"][self.level]:
            return True
        else:
            return False

    def checkLook(self, array):
        for i, elems in enumerate(array):
            for elem in elems:
                if self.checkFood() and elem == "food":
                    self.actions = CONSTANTS["move_to_case"][i]
                    self.handleActions()
                    self.takeObject(elem)
                    return
                if self.checkRessource(elem):
                    self.actions = CONSTANTS["move_to_case"][i]
                    self.handleActions()
                    self.takeObject(elem)
                    return
        self.forward()

    def __parseLookString(self, array):
        array = array.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "")
        result = array.split(',')
        for i in range(len(result)):
            result[i] = result[i].strip().split(' ')
        print (result)
        return result

    def countPlayerOnTile(self, array):
        count = array[0].count("player")
        return count

    def handleActions(self):
        while len(self.actions) > 0:
            print(self.actions)
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
        #
        # LISTEN TO HAVE THE NEW TILE "message K, elevation for level x"
        #
        # newtile = getData()
        # self.moveToElevation(newtile)

    def start(self):
        while True:
            self.inventory()
            print("Inventory >", self.food, self.linemate)
            self.look()
            if self.checkElevation():
                    self.dropItemsForElevation()
                    self.fork()
                    self.startIncantation()
                    l = self.client.getData()
                    if l != "ko\n":
                        self.level += 1
                        sys.exit()
