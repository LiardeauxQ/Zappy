/*
** EPITECH PROJECT, 2018
** init_packets.c
** File description:
** init packet registers
*/

#include "graphical/protocols.h"
#include "graphical/packets.h"
#include "graphical/commands.h"

int init_client_packets(phr_t *reg)
{
    if (reg == 0x0)
        return (-1);
    add_pkt_info(reg, init_pkt(1, 0, "CLT_PROTOCOL_ADDONS", 0x0));
    add_pkt_info(reg, init_pkt(2, 0, "CLT_MAP_SIZE", &send_map_size));
    add_pkt_info(reg, init_pkt(3, 0, "CLT_TILE_CONTENT", &send_tile_content));
    add_pkt_info(reg, init_pkt(4, 0, "CLT_MAP_CONTENT", &send_map_content));
    add_pkt_info(reg, init_pkt(5, 0, "CLT_TEAMS_NAMES", &get_name_teams));
    add_pkt_info(reg, init_pkt(6, 0, "CLT_PLAYER_POSITION",
                &get_player_position));
    add_pkt_info(reg, init_pkt(7, 0, "CLT_PLAYER_LEVEL", &get_player_level));
    add_pkt_info(reg, init_pkt(8, 0, "CLT_PLAYER_INVENTORY",
                &get_player_inventory));
    add_pkt_info(reg, init_pkt(9, 0, "CLT_TIME_UNIT_REQUEST", &get_time_unit));
    add_pkt_info(reg, init_pkt(10, 0, "CLT_TIME_UNIT_CHANGE",
                &get_time_update));
    add_pkt_info(reg, init_pkt(11, 0, "CLT_CLOSE_CONNECTION",
                &get_close_connection));
    return (0);
}

int init_server_environnements_packets(phr_t *reg)
{
    if (reg == 0x0)
        return (-1);
    add_pkt_info(reg, init_pkt(12, 0, "SRV_PROTOCOL_ADDONS", 0x0));
    add_pkt_info(reg, init_pkt(13, 0, "SRV_MAP_SIZE", 0x0));
    add_pkt_info(reg, init_pkt(14, 0, "SRV_TILE_CONTENT", &send_tile_content));
    add_pkt_info(reg, init_pkt(15, 0, "SRV_TEAMS_NAMES", &send_name_teams));
    add_pkt_info(reg, init_pkt(16, 0, "SRV_NEW_PLAYER_CONNECT",
                &send_player_connection));
    add_pkt_info(reg, init_pkt(17, 0, "SRV_PLAYER_POSITION",
                &send_player_position));
    add_pkt_info(reg, init_pkt(18, 0, "SRV_PLAYER_LEVEL", &send_player_level));
    add_pkt_info(reg, init_pkt(19, 0, "SRV_PLAYER_INVENTORY",
                &send_player_inventory));
    add_pkt_info(reg, init_pkt(20, 0, "SRV_EXPULSION",
                &send_player_expulsion));
    add_pkt_info(reg, init_pkt(21, 0, "SRV_BROADCAST", &send_broadcast));
    return (0);
}

int init_server_actions_packets1(phr_t *reg)
{
    if (reg == 0x0)
        return (-1);
    add_pkt_info(reg, init_pkt(22, 0, "SRV_INCANTATION_START",
                &send_incantation_start));
    add_pkt_info(reg, init_pkt(23, 0, "SRV_INCANTATION_END",
                &send_incantation_end));
    add_pkt_info(reg, init_pkt(24, 0, "SRV_EGG_LAYING", &send_laying_egg));
    add_pkt_info(reg, init_pkt(25, 0, "SRV_RESOURCE_DROP",
                &send_resource_drop));
    add_pkt_info(reg, init_pkt(26, 0, "SRV_RESOURCE_COLLECT",
                &send_resource_collect));
    return (0);
}

int init_server_actions_packets2(phr_t *reg)
{
    if (reg == 0x0)
        return (-1);
    add_pkt_info(reg, init_pkt(27, 0, "SRV_PLAYER_DEATH", &send_player_death));
    add_pkt_info(reg, init_pkt(28, 0, "SRV_EGG_LAYED", &send_layed_egg));
    add_pkt_info(reg, init_pkt(29, 0, "SRV_EGG_HATCHING", &send_hatching_egg));
    add_pkt_info(reg, init_pkt(30, 0, "SRV_PLAYER_CONNECT_EGG",
                &send_egg_connection));
    add_pkt_info(reg, init_pkt(31, 0, "SRV_PLAYER_DEATH_EGG",
                &send_egg_hatched_death));
    add_pkt_info(reg, init_pkt(32, 0, "SRV_TIME_UNIT_REQUEST",
                &send_time_unit));
    add_pkt_info(reg, init_pkt(33, 0, "SRV_TIME_UNIT_CHANGE",
                &send_time_update));
    add_pkt_info(reg, init_pkt(34, 0, "SRV_END_GAMES", &send_end_game));
    return (0);
}

int init_server_additionals_packets(phr_t *reg)
{
    if (reg == 0x0)
        return (-1);
    add_pkt_info(reg, init_pkt(35, 0, "SRV_MESSAGE_FROM_SRV",
                &send_message_to_client));
    add_pkt_info(reg, init_pkt(36, 0, "SRV_UNKNOWN_COMMAND",
                &unknown_command));
    add_pkt_info(reg, init_pkt(37, 0, "SRV_COMMAND_PARAMETER", 0x0));
    add_pkt_info(reg, init_pkt(40, 0, "SRV_CUSTOM", 0x0));
    return (0);
}
