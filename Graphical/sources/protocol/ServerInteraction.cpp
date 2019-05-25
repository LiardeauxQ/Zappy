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

void communication::ServerInteraction::sendPacket(uint8_t id, uint16_t size, uint16_t subid)
{
    packet_header hdr = {id, PROTOCOL_VERSION, size, subid};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestMapSize(void) const
{
    packet_header hdr = {CLT_MAP_SIZE, PROTOCOL_VERSION, 0x0, 0x0};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestTileContent(void) const
{
    packet_header hdr = {CLT_TILE_CONTENT, PROTOCOL_VERSION, 0x0, 0x0};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestMapContent(void) const
{
    packet_header hdr = {CLT_MAP_CONTENT, PROTOCOL_VERSION, 0x0, 0x0};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestPlayerPosition(void) const
{
    packet_header hdr = {CLT_PLAYER_POSITION, PROTOCOL_VERSION, 0x0, 0x0};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestPlayerLevel(void) const
{
    packet_header hdr = {CLT_PLAYER_LEVEL, PROTOCOL_VERSION, 0x0, 0x0};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestPlayerInventory(void) const
{
    packet_header hdr = {CLT_PLAYER_INVENTORY, PROTOCOL_VERSION, 0x0, 0x0};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestTimeUnit(void) const
{
    packet_header hdr = {CLT_TIME_UNIT_REQUEST, PROTOCOL_VERSION, 0x0, 0x0};

    write(_sockfd, &hdr, sizeof(hdr));
}

void communication::ServerInteraction::requestTimeUpdate(void) const
{
    packet_header hdr = {CLT_TIME_UNIT_CHANGE, PROTOCOL_VERSION, 0x0, 0x0};

    write(_sockfd, &hdr, sizeof(hdr));
}
