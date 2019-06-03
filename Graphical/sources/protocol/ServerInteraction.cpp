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
        exit(84);
    _sockfd = socket(AF_INET, SOCK_STREAM, 6);
    if (connect(_sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
        exit(84);
}

void communication::ServerInteraction::sendPacket(uint8_t id, uint16_t size, uint16_t subid) const
{
    packet_header hdr = {id, PROTOCOL_VERSION, size, subid};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestMapSize(void) const
{
    sendPacket(CLT_MAP_SIZE, 0x0, 0x0);
}

void communication::ServerInteraction::requestTileContent(void) const
{
    sendPacket(CLT_TILE_CONTENT, 0x0, 0x0);
}

void communication::ServerInteraction::requestMapContent(void) const
{
    sendPacket(CLT_MAP_CONTENT, 0x0, 0x0);
}

void communication::ServerInteraction::requestTeamsNames(void) const
{
    sendPacket(CLT_TEAMS_NAMES, 0x0, 0x0);
}

void communication::ServerInteraction::requestPlayerPosition(void) const
{
    sendPacket(CLT_PLAYER_POSITION, 0x0, 0x0);
}

void communication::ServerInteraction::requestPlayerLevel(void) const
{
    sendPacket(CLT_PLAYER_LEVEL, 0x0, 0x0);
}

void communication::ServerInteraction::requestPlayerInventory(void) const
{
    sendPacket(CLT_PLAYER_INVENTORY, 0x0, 0x0);
}

void communication::ServerInteraction::requestTimeUnit(void) const
{
    sendPacket(CLT_TIME_UNIT_REQUEST, 0x0, 0x0);
}

void communication::ServerInteraction::requestTimeUpdate(void) const
{
    sendPacket(CLT_TIME_UNIT_CHANGE, 0x0, 0x0);
}
