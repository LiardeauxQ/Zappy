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
#include "linked_list.h"

void add_player(world_t *world, const unsigned int team_id)
{
    static int player_id;
    player_t *player = calloc(1, sizeof(player_t));

    if (world == 0x0)
        return;
    player->id = player_id;
    player->team_id = team_id;
    player->x = rand() % world->width;
    player->y = rand() % world->height;
    player->direction = rand() % 4;
    memset(player->resources, 0, DEFAULT_RESOURCES_NUMBER);
    append(&world->players, player);
    player_id++;
}
