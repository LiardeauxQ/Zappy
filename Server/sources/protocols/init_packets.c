/*
** EPITECH PROJECT, 2018
** init_packets.c
** File description:
** init packet registers
*/

#include "packets.h"

void init_client_packets(phr_t *reg)
{
    add_pkt_info(reg, init_pkt(1, 0, "CLT_PROTOCOL_ADDONS", 0x0));
    add_pkt_info(reg, init_pkt(2, 0, "CLT_MAP_SIZE", 0x0));
    add_pkt_info(reg, init_pkt(3, 0, "CLT_TILE_CONTENT", 0x0));
    add_pkt_info(reg, init_pkt(4, 0, "CLT_MAP_CONTENT", 0x0));
    add_pkt_info(reg, init_pkt(5, 0, "CLT_TEAMS_NAMES", 0x0));
    add_pkt_info(reg, init_pkt(6, 0, "CLT_PLAYER_POSITION", 0x0));
    add_pkt_info(reg, init_pkt(7, 0, "CLT_PLAYER_LEVEL", 0x0));
    add_pkt_info(reg, init_pkt(8, 0, "CLT_PLAYER_INVENTORY", 0x0));
    add_pkt_info(reg, init_pkt(9, 0, "CLT_TIME_UNIT_REQUEST", 0x0));
    add_pkt_info(reg, init_pkt(10, 0, "CLT_TIME_UNIT_CHANGE", 0x0));
    add_pkt_info(reg, init_pkt(11, 0, "CLT_CUSTOM", 0x0));
}

void init_server_environnements_packets(phr_t *reg)
{
    add_pkt_info(reg, init_pkt(12, 0, "SRV_PROTOCOL_ADDONS", 0x0));
    add_pkt_info(reg, init_pkt(13, 0, "SRV_MAP_SIZE", 0x0));
    add_pkt_info(reg, init_pkt(14, 0, "SRV_TILE_CONTENT", 0x0));
    add_pkt_info(reg, init_pkt(15, 0, "SRV_TEAMS_NAMES", 0x0));
    add_pkt_info(reg, init_pkt(16, 0, "SRV_NEW_PLAYER_CONNECT", 0x0));
    add_pkt_info(reg, init_pkt(17, 0, "SRV_PLAYER_POSITION", 0x0));
    add_pkt_info(reg, init_pkt(18, 0, "SRV_PLAYER_LEVEL", 0x0));
    add_pkt_info(reg, init_pkt(19, 0, "SRV_PLAYER_INVENTORY", 0x0));
    add_pkt_info(reg, init_pkt(20, 0, "SRV_EXPULSION", 0x0));
    add_pkt_info(reg, init_pkt(21, 0, "SRV_BROADCAST", 0x0));
}

void init_server_actions_packets(phr_t *reg)
{
    add_pkt_info(reg, init_pkt(22, 0, "SRV_INCANTATION_START", 0x0));
    add_pkt_info(reg, init_pkt(23, 0, "SRV_INCANTATION_END", 0x0));
    add_pkt_info(reg, init_pkt(24, 0, "SRV_EGG_LAYING", 0x0));
    add_pkt_info(reg, init_pkt(25, 0, "SRV_RESOURCE_DROP", 0x0));
    add_pkt_info(reg, init_pkt(26, 0, "SRV_RESOURCE_COLLECT", 0x0));
    add_pkt_info(reg, init_pkt(27, 0, "SRV_PLAYER_DEATH", 0x0));
    add_pkt_info(reg, init_pkt(28, 0, "SRV_EGG_LAYED", 0x0));
    add_pkt_info(reg, init_pkt(29, 0, "SRV_EGG_HATCHING", 0x0));
    add_pkt_info(reg, init_pkt(30, 0, "SRV_PLAYER_CONNECT_EGG", 0x0));
    add_pkt_info(reg, init_pkt(31, 0, "SRV_PLAYER_DEATH_EGG", 0x0));
    add_pkt_info(reg, init_pkt(32, 0, "SRV_TIME_UNIT_REQUEST", 0x0));
    add_pkt_info(reg, init_pkt(33, 0, "SRV_TIME_UNIT_CHANGE", 0x0));
    add_pkt_info(reg, init_pkt(34, 0, "SRV_END_GAMES", 0x0));
}

void init_server_additionals_packets(phr_t *reg)
{
    add_pkt_info(reg, init_pkt(35, 0, "SRV_MESSAGE_FROM_SRV", 0x0));
    add_pkt_info(reg, init_pkt(36, 0, "SRV_UNKNOWN_COMMAND", 0x0));
    add_pkt_info(reg, init_pkt(37, 0, "SRV_COMMAND_PARAMETER", 0x0));
    add_pkt_info(reg, init_pkt(40, 0, "SRV_CUSTOM", 0x0));
}
