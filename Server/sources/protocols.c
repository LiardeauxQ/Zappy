/*
** EPITECH PROJECT, 2018
** protocols.c
** File description:
** handle graphical protocol
*/

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "protocols.h"

//const struct protocol_info_s protocol_info[] = {
//    {1, "CLT_PROTOCOL_ADDONS"},
//    {2, "CLT_MAP_SIZE"},
//    {3, "CLT_TILE_CONTENT"},
//    {4, "CLT_MAP_CONTENT"},
//    {5, "CLT_TEAMS_NAMES"},
//    {6, "CLT_PLAYER_POSITION"},
//    {7, "CLT_PLAYER_LEVEL"},
//    {8, "CLT_PLAYER_INVENTORY"},
//    {9, "CLT_TIME_UNIT_REQUEST"},
//    {10, "CLT_TIME_UNIT_CHANGE"},
//    {11, "CLT_CUSTOM"},
//    {12, "SRV_PROTOCOL_ADDONS"},
//    {13, "SRV_MAP_SIZE"},
//    {14, "SRV_TILE_CONTENT"},
//    {15, "SRV_TEAMS_NAMES"},
//    {16, "SRV_NEW_PLAYER_CONNECT"},
//    {17, "SRV_PLAYER_POSITION"},
//    {18, "SRV_PLAYER_LEVEL"},
//    {19, "SRV_PLAYER_INVENTORY"},
//    {20, "SRV_EXPULSION"},
//    {21, "SRV_BROADCAST"},
//    {22, "SRV_INCANTATION_START"},
//    {23, "SRV_INCANTATION_END"},
//    {24, "SRV_EGG_LAYING"},
//    {25, "SRV_RESOURCE_DROP"},
//    {26, "SRV_RESOURCE_COLLECT"},
//    {27, "SRV_PLAYER_DEATH"},
//    {28, "SRV_EGG_LAYED"},
//    {29, "SRV_EGG_HATCHING"},
//    {30, "SRV_PLAYER_CONNECT_EGG"},
//    {31, "SRV_PLAYER_DEATH_EGG"},
//    {32, "SRV_TIME_UNIT_REQUEST"},
//    {33, "SRV_TIME_UNIT_CHANGE"},
//    {34, "SRV_END_GAMES"},
//    {35, "SRV_MESSAGE_FROM_SRV"},
//    {36, "SRV_UNKNOWN_COMMAND"},
//    {37, "SRV_COMMAND_PARAMETER"},
//    {40, "SRV_CUSTOM"},
//    {0, 0X0}
//};

pkt_handler_t *init_packet(int id, ...)
{
    pkt_handler_t *pkt = calloc(1, sizeof(pkt_handler_t));
    va_list ap;

    va_start(ap, id);
    pkt->id = id;
    pkt->subid = va_arg(ap, int);
    pkt->name = strdup(va_arg(ap, char *));
    pkt->handler = va_arg(ap, data_handler);
    va_end(ap);
    return (pkt);
}
