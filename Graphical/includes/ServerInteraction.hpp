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
#include <fcntl.h>
#include <errno.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "protocols.h"
#include "Errors.hpp"
#include "EventManager.hpp"
#include "Packet.hpp"

namespace communication {
    class ServerInteraction {
    public:
        ServerInteraction(unsigned int port, const std::string &ipAddress);
        ServerInteraction();
        ~ServerInteraction();

        srv_map_size_t requestMapSize(void) const;
        void requestTileContent(unsigned int x, unsigned int y) const;
        void requestMapContent(void) const;
        void requestTeamsNames(void) const;
        void requestPlayerPosition(unsigned int id) const;
        void requestPlayerLevel(unsigned int id) const;
        void requestPlayerInventory(unsigned int id) const;
        void requestTimeUnit(void) const;
        void requestTimeUpdate(void) const;

        void listenSocket(void);
        void setNonBlockingSocket(void);
        
        unsigned int getSocket(void) const { return sockfd; }
        EventManager<char*> events;
    private:
        void requestCloseConnection(void) const;

        unsigned int __attribute__((unused)) port;
        int sockfd;
    };
}
