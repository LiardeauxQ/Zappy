/*
** EPITECH PROJECT, 2018
** elevation_handler.c
** File description:
** Handle elevation
*/

#include <stdio.h>
#include <stdlib.h>

#include "ai/handlers/elevation_handler.h"

///
/// Rules to authorize or not the elevation of a player
/// The first dimension associates a set of rules with a level. 
/// For example, a user who want to elevate from level 1 to 2 should look at
///   elevation_rules[0].
/// The rules are organised following the following scheme:
///   Number of player, Linemate, Deraumere, Sibur, Mendiane, Phiras, Thystame
///
static int elevation_rules[7][7] = {
    {
        1, 1, 0, 0, 0, 0, 0
    }, {
        2, 1, 1, 1, 0, 0, 0
    }, {
        2, 2, 0, 1, 0, 2, 0
    }, {
        4, 1, 1, 2, 0, 1, 0
    }, {
        4, 1, 2, 1, 3, 0, 0
    }, {
        6, 1, 2, 3, 0, 1, 0
    }, {
        6, 2, 2, 2, 2, 2, 1
    }
};

int is_enough_users(world_t *world, tile_content_t *tile, player_t *player)
{
    int i = 0;
    player_t *tmp_player = 0x0;
    node_t *player_id_cursor = tile->players_id.head;

    for (; player_id_cursor; player_id_cursor = player_id_cursor->next) {
        tmp_player = get_player(world->players,
                *(unsigned int*) player_id_cursor->data);
        if (tmp_player->level == player->level)
            i++;
    }
    if (i < elevation_rules[player->level - 1][0])
        return (0);
    return (1);
}

int elevation_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    char *res = 0x0;
    tile_content_t tile = world->tiles[player->x][player->y];

    if (!is_enough_users(world, &tile, player)) {
        set_response("ko\n");
        return (INVALID_PARAMETERS);
    }
    for (int i = 1; tile.resources[i] != -1 &&
            i < DEFAULT_RESOURCES_NUMBER - 1; i++) {
        if (tile.resources[i] < elevation_rules[player->level - 1][i]) {
            set_response("ko\n");
            return (INVALID_PARAMETERS);
        }
    }
    res = calloc(1, strlen("Elevation underway\nCurrent level: k\n") + 1);
    strcat(res, "Elevation underway\nCurrent level: ");
    sprintf(res + strlen("Elevation underway\nCurrent level: "),
            "%d\n", player->level);
    set_response(res);
    return (NO_ERROR);
}
