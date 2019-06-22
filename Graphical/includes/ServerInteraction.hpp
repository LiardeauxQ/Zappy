/*
** EPITECH PROJECT, 2018
** ServerInteraction.hpp
** File description:
** Protocol header
*/

#pragma once

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include <iostream>
#include <string>

#include "protocols.h"
#include "Errors.hpp"

namespace communication {

    template <class T>
    class Packet {
    public:
        Packet(uint8_t id, int sockfd, uint16_t size = 0, uint16_t subid = 0);
        ~Packet() = default;

        Packet &operator<<(const T *data); // send
        void operator>>(T *data); // receive
    private:
        uint8_t id;
        int sockfd;
        uint16_t size;
        uint16_t subid;
    };

    class ServerInteraction {
    public:
        ServerInteraction(unsigned int port, const std::string &ipAddress);
        ServerInteraction();
        ~ServerInteraction();

        void requestMapSize(void) const;
        void requestTileContent(unsigned int x, unsigned int y) const;
        void requestMapContent(void) const;
        void requestTeamsNames(void) const;
        void requestPlayerPosition(unsigned int id) const;
        void requestPlayerLevel(unsigned int id) const;
        void requestPlayerInventory(unsigned int id) const;
        void requestTimeUnit(void) const;
        void requestTimeUpdate(void) const;
        
        unsigned int getSocket(void) const { return _sockfd; }
    private:
        void requestCloseConnection(void) const;

        unsigned int _port;
        int _sockfd;
    };
}
