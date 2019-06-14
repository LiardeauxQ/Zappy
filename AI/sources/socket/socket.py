import socket
import random


class Socket:

    def __init__(self, host = "localhost", port = 3630):
        self.socketID = random.randint(0, 200000)
        self.host = host
        self.port = port 
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connected = False

    def connect(self):
        try:
            self.socket.connect((self.host, self.port))
        except:
            print("socket [", self.socketID, "]","Connection Error")
            self.connect = False
            return 84
        else:
            print ("socket [", self.socketID, "]","Connection on http://", self.host, ":", self.port, sep='')
            self.connect = True
            return 0
        
    def sendMessage(self, message):
        if self.connect == False:
            print("socket [", self.socketID, "]","Connection Error")
            self.connect = False
            return 84
        try:
            self.socket.send(message)
        except:
            print("socket [", self.socketID, "]","Connection Error")
            self.connect = False
            return 84
        else:
            print("socket [", self.socketID, "]", "Send :", message)
            return 0


    def closeConection(self):
        if self.connect == False:
            print("socket [", self.socketID, "]","Connection Error")
            self.connect = False
            return 84
        try:
            self.socket.close()
        except:
            print("socket [", self.socketID, "]","Connection Error")
            self.connect = False
            return 84
        finally:
            print("socket [", self.socketID, "]","Connection Close")
            self.connect = False
            return 0


    def getData(self):
        if self.connect == False:
            print("socket [", self.socketID, "]","Connection Error")
            self.connect = False
            return 84
        try:
            recv = self.socket.recv()
        except:
            print("socket [", self.socketID, "]","Connection Error")
            self.connect = False
            return 84
        else:
            print("socket [", self.socketID, "]","recive :", recv)
            return recv

    def getInfo(self):
        return self.socketID, self.connected, self.host, self.port


