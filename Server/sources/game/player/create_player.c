/*
** EPITECH PROJECT, 2018
** create_player.c
** File description:
** create playerat the connection
*/

#include <string.h>

#include "world.h"
#include "player.h"
#include "graphical/protocols.h"

void add_player(world_t *world, const char *team_name)
{
    static int player_id;

    if (world == 0x0)
        return;
    world->players = realloc(world->players, (player_id + 2)
        * sizeof(srv_new_player_connect_t));
    world->players[player_id].player_num = player_id;
    world->players[player_id].x = rand() % world->map.width;
    world->players[player_id].y = rand() % world->map.height;
    world->players[player_id].orientation = rand() % 4;
    world->players[player_id].level = 0;
    if (team_name != 0x0 && strlen(team_name) < SHORT_MSG_LEN)
        strcpy(world->players[player_id].team_name, team_name);
    world->players[player_id + 1] = (srv_new_player_connect_t){0};
    player_id++;
}
