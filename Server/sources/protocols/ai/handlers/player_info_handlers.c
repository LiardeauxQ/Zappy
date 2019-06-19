/*
** EPITECH PROJECT, 2018
** player_info_handlers.c
** File description:
** Handle every action on player informations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ai/handlers/player_info_handlers.h"

int tile_to_str(world_t *world, int *coords, int team_id)
{
    char *str = calloc(1, 1);
    char *buffer = 0x0;
    player_t *player = {0};
    tile_content_t tile = world->tiles[coords[0]][coords[1]];
    node_t *player_id_cursor = tile.players_id.head;

    for (int i = 0; tile.resources[i] != -1; i++) {
        buffer = world->resources[tile.resources[i]].name;
        str = realloc(str, strlen(str) + strlen(buffer) + 2);
        strcat(str, buffer);
        if (tile.resources[i + 1] != -1)
            strcat(str, " ");
    }
    for (int i = 0; (player_id_cursor = player_id_cursor->next); i++) {
        player = get_player(world->players, (int) player_id_cursor->data);
        if (player && (int) player->team_id && str[0]) {
            str = realloc(str, strlen(str) + strlen(" player"));
            strcat(str, " player");
        } else if (player && (int) player->team_id) {
            str = realloc(str, strlen(str) + strlen("player"));
            strcat(str, "player");
        }
    }
    return (str);
}

void append_tile_to_look_table(char **look_table, char *tile)
{
    if (!*look_table[0])
        *look_table[0] = '[';
    *look_table = realloc(*look_table, strlen(*look_table) + strlen(tile) + 2);
    strcat(*look_table, tile);
    strcat(*look_table, ",");
}

int look_handler(world_t *world, player_t *player, const uint16_t limit_cycles,
        const char __attribute__((unused)) **args)
{
    unsigned int current_line_start[2] = {player->x, player->y};
    char *look_table = calloc(1, 2);

    for (int i = 0; i <= player->level; i++) {
        for (int j = 0; j < 1 + i * 2; j++) {
            append_tile_to_look_table(look_table,
                tile_to_str(world, current_line_start, player->team_id));
            next_case(world, current_line_start, player->orientation, 1);
        }
        next_case(world, current_line_start, player->orientation, 2 + i * 2);
        next_case(world, current_line_start, player->orientation - 1, 1);
    }
    return (0);
}

int connect_nbr_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char __attribute__((unused)) **args)
{
    // Unimplemented
    return (0);
}

int death_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char __attribute__((unused)) **args)
{
    // send_message("dead");
    return (NO_ERROR);
}
