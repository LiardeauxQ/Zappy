import socket
import random
import time


class SocketZappy:

    def __init__(self, host = 'localhost', port = 3630):
        self.socketID = random.randint(0, 200000)
        self.host = host
        self.port = port 
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connected = False

    def connect_zappy(self):

        buff_size = 2048;
        buff = bytearray(buff_size)
        try:
            self.socket.connect((self.host, self.port))
            r = self.socket.recv_into(buff, buff_size);
        except:
            print("socket [", self.socketID, "]","Connection Error")
            self.connected = False
            return 84
        else:
            print ("socket [", self.socketID, "]","Connection on http://", self.host, ":", self.port, sep='')
            self.connected = True
            return 0
        
    def sendMessage(self, message):
        try:
            self.socket.send(str.encode(message))
        except:
            print("socket [", self.socketID, "]","Message Error")
            self.connected = False
            return 84
        else:
            print("socket [", self.socketID, "]", "Send :", message)
            return self.getData()


    def closeConection(self):
        if self.connected == False:
            print("socket [", self.socketID, "]","Connection Error")
            self.connected = False
            return 84
        self.socket.close()


    def getData(self):
        if self.connected == False:
            print("socket [", self.socketID, "]","Connection Error")
            self.connected = False
            return 84
        buff_size = 2048;
        buff = bytearray(buff_size)
        try:
            self.socket.recv_into(buff, buff_size);
        except:
            print("socket [", self.socketID, "]","Connection Error")
            self.connected = False
            return 84
        else:
            print("socket [", self.socketID, "]","recive :", buff.decode())
            return buff.decode()

    def getInfo(self):
        return self.socketID, self.connected, self.host, self.port


