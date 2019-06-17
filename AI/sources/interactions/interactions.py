from sources.socket.socket import *

class Player:

    def __init__(self):
        self.client = Socket()

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
