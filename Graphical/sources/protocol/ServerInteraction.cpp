/*
** EPITECH PROJECT, 2018
** ServerInteraction.cpp
** File description:
** Handle protocol
*/

#include "ServerInteraction.hpp"

communication::ServerInteraction::ServerInteraction(unsigned int port,
        const std::string &ipAddress) : _port(port)
{
    struct sockaddr_in sockaddr;

    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(_port);
    if (inet_aton(ipAddress.c_str(), &sockaddr.sin_addr) == -1)
        throw ServerInteractionErrors("Can't convert ip address");
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "Try connection to host: " << ipAddress << std::endl;
    if (connect(_sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
        throw ServerInteractionErrors("Unable to connect to server");
    std::cout << "Successful connection to host: " << ipAddress << std::endl;
}

communication::ServerInteraction::ServerInteraction() : _port(0), _sockfd(-1)
{
}

void communication::ServerInteraction::sendPacket(uint8_t id, uint16_t size, uint16_t subid) const
{
    packet_header hdr = {id, PROTOCOL_VERSION, size, subid};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestMapSize(void) const
{
    sendPacket(CLT_MAP_SIZE, 0, 0);
}

void communication::ServerInteraction::requestTileContent(void) const
{
    sendPacket(CLT_TILE_CONTENT, 0, 0);
}

void communication::ServerInteraction::requestMapContent(void) const
{
    sendPacket(CLT_MAP_CONTENT, 0, 0);
}

void communication::ServerInteraction::requestTeamsNames(void) const
{
    sendPacket(CLT_TEAMS_NAMES, 0, 0);
}

void communication::ServerInteraction::requestPlayerPosition(void) const
{
    sendPacket(CLT_PLAYER_POSITION, 0, 0);
}

void communication::ServerInteraction::requestPlayerLevel(void) const
{
    sendPacket(CLT_PLAYER_LEVEL, 0, 0);
}

void communication::ServerInteraction::requestPlayerInventory(void) const
{
    sendPacket(CLT_PLAYER_INVENTORY, 0, 0);
}

void communication::ServerInteraction::requestTimeUnit(void) const
{
    sendPacket(CLT_TIME_UNIT_REQUEST, 0, 0);
}

void communication::ServerInteraction::requestTimeUpdate(void) const
{
    sendPacket(CLT_TIME_UNIT_CHANGE, 0, 0);
}
