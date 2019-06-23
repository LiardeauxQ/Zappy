import socket
import random
import time
import sys
import logging

class SocketZappy:

    def __init__(self, host = 'localhost', port = 6000):
        self.socketID = random.randint(0, 200000)
        self.host = host
        self.port = port 
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connected = False

    def connect_zappy(self):
        buff_size = 2048;
        buff = bytearray(buff_size)
        self.socket.connect((self.host, self.port))
        self.socket.recv_into(buff, buff_size);
        logging.debug("socket [" + str(self.socketID) + "] Connection on http://"+ str(self.host) + ":"+ str(self.port)+  " -> " + buff.decode())
        self.connected = True
        return 0
        
    def sendMessage(self, message: str):
        try:
            self.socket.send(str.encode(message))
        except:
            logging.debug("socket [" + str(self.socketID) + "] Message Error")
            self.connected = False
            return 84
        else:
            logging.debug("socket [" + str(self.socketID) + "] Send :" + message)
            return self.getData()


    def closeConection(self):
        if self.connected == False:
            logging.debug("socket [" + str(self.socketID) + "] Connection Error")
            self.connected = False
            return 84
        self.socket.close()


    def getData(self):
        if self.connected == False:
            logging.debug("socket [" + str(self.socketID) + "] Connection Error")
            self.connected = False
            return 84
        buff_size = 2040800;
        buff = bytearray(buff_size)
        self.socket.recv_into(buff, buff_size);
        logging.debug("socket [" + str(self.socketID) + "] receive :" + buff.decode())
        first = True
        if "message" in buff.decode():
            buff2 = bytearray(buff_size)
            while first or "message" in buff2.decode():
                buff2 = ""
                buff2 = bytearray(buff_size)
                first = False
                self.socket.recv_into(buff2, buff_size);
                logging.debug("socket [" + str(self.socketID) + "] receive 2:" + buff2.decode())
                print("socket [" + str(self.socketID) + "] receive 2:" + buff2.decode())
            return buff.decode(), buff2.decode()
        else:
             return "", buff.decode()

    def getInfo(self):
        return self.socketID, self.connected, self.host, self.port


