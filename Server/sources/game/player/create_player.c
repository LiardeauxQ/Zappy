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

void add_player(world_t *world, const unsigned int team_id)
{
    static int player_id;

    if (world == 0x0)
        return;
    world->players = realloc(world->players, (player_id + 2)
        * sizeof(srv_new_player_connect_t));
    world->players[player_id].id = player_id;
    world->players[player_id].team_id = team_id;
    world->players[player_id].x = rand() % world->width;
    world->players[player_id].y = rand() % world->height;
    world->players[player_id].direction = rand() % 4;
    world->players[player_id].level = 0;
    world->players[player_id].hp = 0;
    memset(world->players[player_id].resources, 0, DEFAULT_RESOURCES_NUMBER);
    player_id++;
}
