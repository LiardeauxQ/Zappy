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

void tile_to_str(world_t *world, size_t *coords, int team_id, char **str)
{
    char *buffer = 0x0;
    player_t *player = 0x0;
    tile_content_t tile = world->tiles[coords[0]][coords[1]];

    for (node_t *player_id_cursor = tile.players_id.head; player_id_cursor;
            player_id_cursor = player_id_cursor->next) {
        player = get_player(world->players,
                *(unsigned int*) player_id_cursor->data);
        if (player && (int) player->team_id == team_id) {
            *str = realloc(*str,
                strlen(*str) + strlen((*str[0]) ? " player" : "player ") + 1);
            strcat(*str, (*str[0]) ? " player" : "player ");
        }
    }
    for (int i = 0; tile.resources[i] != -1; i++) {
        buffer = world->resources[tile.resources[i]].name;
        *str = realloc(*str, strlen(*str) + strlen(buffer) + 2);
        strcat(*str, buffer);
        (tile.resources[i + 1] != -1) ? strcat(*str, " ") : 0x0;
    }
}

void append_tile_to_look_table(world_t *world, size_t *coords, int team_id,
        char **look_table)
{
    char *tile = calloc(1, 1);

    tile_to_str(world, coords, team_id, &tile);
    if (!*look_table[0])
        *look_table[0] = '[';
    *look_table = realloc(*look_table, strlen(*look_table) + strlen(tile) + 3);
    strcat(*look_table, tile);
    strcat(*look_table, ",");
}

int look_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    size_t current_line_start[2] = {player->x, player->y};
    char *look_table = calloc(1, 2);

    for (int i = 0; i <= player->level; i++) {
        for (int j = 0; j < 1 + i * 2; j++) {
            append_tile_to_look_table(world, current_line_start,
                    player->team_id, &look_table);
            next_case(world, current_line_start, player->orientation, 1);
        }
        next_case(world, current_line_start, player->orientation, 2 + i * 2);
        next_case(world, current_line_start, player->orientation - 1, 1);
    }
    look_table[strlen(look_table) - 1] = ']';
    set_response(look_table);
    return (NO_ERROR);
}

int connect_nbr_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    int player_in_team = 0;
    char *res = 0x0;
    node_t *player_node = world->players.head;

    for (int i = 0; player_node; i++) {
        if (((player_t *) player_node->data)->team_id == player->team_id)
            player_in_team += 1;
        player_node = player_node->next;
    }
    res = calloc(1, sizeof(char) * (snprintf(0x0, 0, "%d",
                    world->max_team_size - player_in_team) + 1));
    sprintf(res, "%d", world->max_team_size - player_in_team);
    set_response(res);
    return (NO_ERROR);
}

int death_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    remove_player(world, player);
    set_response("dead");
    return (NO_ERROR);
}
