from AI.sources.socket.socket import *
from AI.sources.ressources.dictionaries import *
from AI.sources.elevation.playerNeededForElevation import *
import sys
import os
import logging
import subprocess
import math

class Player:

    def __init__(self, port = 6000, team = "test_team", host = "localhost"):
        self.client = SocketZappy(host, port)
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
        self.view = []

    def forward(self):
        self.client.sendMessage("Forward\n")

    def right(self):
        self.client.sendMessage("Right\n")

    def left(self):
        self.client.sendMessage("Left\n")

    def look(self):
        m, l = self.client.sendMessage("Look\n")
        l = self. __parseLookString(l)
        self.view = l
        if "message" in m:
            self.moveToElevation(m)
        self.checkLook(l)
        logging.debug(l)

    def inventory(self):
        m, l = self.client.sendMessage("Inventory\n")
        logging.debug(l)
        self.__parseInventoryString(l)
        if "message" in m:
            self.moveToElevation(m) 

    def __parseInventoryString(self, array):
        array = array.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "")
        result = array.split(',')
        for i in range(len(result)):
            result[i] = result[i].strip().split(' ')
        for i in range(len(result)):
            vars(self)[result[i][0]] = int(result[i][1]);
        logging.debug(result)
        return result

    def getPositionFromBroadcast(self, message):
        message = message.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "").replace(",", "")
        result = message.split(" ")
        tmp = result[len(result)]
        return int(tmp[:1])

    def getLevelFromBroadcast(self, message):
        message = message.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "").replace(",", "")
        result = message.split(" ")
        tmp = result[1]
        return int(tmp[:1])

    def checkLevelForBroadcast(self, message):
        if self.level == self.getLevelFromBroadcast(message):
            return True
        else:
            return False

    def broadcast(self, text):
        self.client.sendMessage("Broadcast " + text + "\n")

    def connectNumber(self):
        m, res = self.client.sendMessage("Connect_nbr\n")
        res = res.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "").replace(",", "")
        print ("connectNumber :", res)
        return int(res)

    def fork(self):
        tmp = self.connectNumber()
        if tmp == 0:
            self.client.sendMessage("Fork\n")
        else:
            subprocess.Popen(["./zappy_ai", "-p", str(self.port), "-n", self.team, "-h", self.host])

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
        logging.debug(result)
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
        if name == "player" or name == "food" or name == "":
            return False
        elif vars(self)[name] < CONSTANTS[name + "_desirable"][self.level]:
            return True
        else:
            return False

    def checkLook(self, array):
        for i, elems in enumerate(array):
            for elem in elems:
                if self.checkFood() == False and elem == "food":
                    self.actions = self.chooseDirection(i)
                    self.handleActions()
                    self.takeObject(elem)
                    return
                if self.checkRessource(elem):
                    self.actions = self.chooseDirection(i)
                    self.handleActions()
                    self.takeObject(elem)
                    return
        self.forward()

    def __parseLookString(self, array):
        array = array.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "")
        result = array.split(',')
        for i in range(len(result)):
            result[i] = result[i].strip().split(' ')
        logging.debug(result)
        return result

    def countPlayerOnTile(self, array):
        count = array[0].count("player")
        print("PLAYER ON TILE IS EGAL TO:", count)
        return count

    def updateLevel(self):
        m, lvl = self.client.getData()
        lvl = lvl.replace("\x00", "").replace("\n", "").replace("[", "").replace("]", "").replace(",", "")
        self.level = int(lvl[-1:])


    def handleActions(self):
        while len(self.actions) > 0:
            logging.debug(self.actions)
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

    def chooseDirection(self, number):
        r = math.floor(math.sqrt(number))
        thresold = (r * r) + r
        result = ["Forward" for i in range(r)]
        if number - thresold < 0:
            result.append("Left")
        elif number - thresold > 0:
            result.append("Right")
        result += ["Forward" for i in range(abs(number - thresold))]
        return result

    def moveToElevation(self, message):
        tile = self.getPositionFromBroadcast(message)
        print("MOVING TO THE ORIGIN OF THE BROADCAST")
        if tile == 0:

            return
        self.actions = CONSTANTS["move_to_sound"][tile]
        self.handleActions()

    def start(self):
        while True:
            logging.debug("Inventory >food " + str(self.food) +
                                "; linemate"+ str(self.linemate) +
                                "; mendiane"+ str(self.mendiane) +
                                "; phiras"+ str(self.phiras) +
                                "; sibur"+ str(self.sibur) +
                                "; thystame"+ str(self.thystame) +
                                "; deraumere"+ str(self.deraumere))
            self.look()
            if self.checkElevation():
                if CONSTANT["playerNeededForElevation"][self.level] == self.countPlayerOnTile(self.view):
                    self.dropItemsForElevation()
                    self.fork()
                    self.startIncantation()
                    self.updateLevel()
                else:
                    self.broadcast("elevation for level " + str(self.level))
                    print("SENDING BROADCAST FOR ELEVATION !!")
            self.inventory()