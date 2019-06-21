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

communication::ServerInteraction::~ServerInteraction()
{
    close(_sockfd);
}

void communication::ServerInteraction::requestMapSize(void) const
{
    Packet<clt_map_size_t> pkt(CLT_MAP_SIZE, _sockfd);
    Packet<srv_map_size_t> pkt2(SRV_MAP_SIZE, _sockfd);

    pkt << 0x0;
    srv_map_size_t map = {0, 0};
    pkt2 >> &map;
    printf("%d %d\n", map.x, map.y);
}

void communication::ServerInteraction::requestTileContent(unsigned int x,
        unsigned int y) const
{
    clt_tile_content_t tile = {x, y};
    Packet<clt_tile_content_t> pkt(CLT_TILE_CONTENT, _sockfd,
            CLT_TILE_CONTENT_LEN);

    pkt << &tile;
}

void communication::ServerInteraction::requestMapContent(void) const
{
    Packet<clt_map_content_t> pkt(CLT_MAP_CONTENT, _sockfd);

    pkt << 0x0;
}

void communication::ServerInteraction::requestTeamsNames(void) const
{
    Packet<clt_teams_names_t> pkt(CLT_TEAMS_NAMES, _sockfd);

    pkt << 0x0;
}

void communication::ServerInteraction::requestPlayerPosition(unsigned int id) const
{
    clt_player_pos_t player = {id};
    Packet<clt_player_pos_t> pkt(CLT_PLAYER_POSITION, _sockfd,
            CLT_PLAYER_POS_LEN);

    pkt << &player;
}

void communication::ServerInteraction::requestPlayerLevel(unsigned int id) const
{
    clt_player_level_t player = {id};
    Packet<clt_player_level_t> pkt(CLT_PLAYER_LEVEL, _sockfd,
            CLT_PLAYER_LEVEL_LEN);

    pkt << &player;
}

void communication::ServerInteraction::requestPlayerInventory(unsigned int id) const
{
    struct clt_player_inventory player = {id};
    Packet<struct clt_player_inventory> pkt(CLT_PLAYER_INVENTORY, _sockfd,
            CLT_PLAYER_INVENTORY_LEN);

    pkt << &player;
}

void communication::ServerInteraction::requestTimeUnit(void) const
{
    Packet<char> pkt(CLT_TIME_UNIT_REQUEST, _sockfd);

    pkt << 0x0;
}

void communication::ServerInteraction::requestTimeUpdate(void) const
{
    Packet<char> pkt(CLT_TIME_UNIT_CHANGE, _sockfd);

    pkt << 0x0;
}

template <class T>
communication::Packet<T>::Packet(uint8_t id, int sockfd, uint16_t size, uint16_t subid)
    : id(id), sockfd(sockfd), size(size), subid(subid)
{
}

template <class T>
communication::Packet<T> &communication::Packet<T>::operator<<(const T *data)
{
    packet_header hdr = {id, PROTOCOL_VERSION, size, subid};

    write(sockfd, &hdr, sizeof(hdr));
    write(sockfd, data, sizeof(T));
    return (*this);
}

template <class T>
void communication::Packet<T>::operator>>(T *data)
{
    packet_header hdr = {0, 0, 0, 0};

    if (read(sockfd, &hdr, PKT_HDR_LEN) != PKT_HDR_LEN
            || hdr.id > SRV_CUSTOM) {
        data = nullptr;
        return;
    }
    read(sockfd, data, hdr.size);
}
