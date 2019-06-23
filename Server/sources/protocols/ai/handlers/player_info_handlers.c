/*
** EPITECH PROJECT, 2018
** player_info_handlers.c
** File description:
** Handle every action on player informations.
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ai/handlers/player_info_handlers.h"

void tile_to_str(world_t *world, pos_t *pos, int team_id, char **str)
{
    char *buffer = 0x0;
    player_t *player = 0x0;
    tile_content_t tile = world->tiles[pos->x][pos->y];

    for (node_t *player_id_cursor = tile.players_id.head; player_id_cursor;
            player_id_cursor = player_id_cursor->next) {
        player = get_player(world->players,
                *(unsigned int*) player_id_cursor->data);
        if (player && (int) player->team_id == team_id) {
            *str = realloc(*str, strlen(*str) + strlen("player ") + 1);
            strcat(*str, "player ");
        }
    }
    for (int i = 0; world->resources[i].name; i++) {
        buffer = world->resources[i].name;
        for (int j = 0; j < tile.resources[i]; j++) {
            *str = realloc(*str, strlen(*str) + strlen(buffer) + 2);
            strcat(strcat(*str, buffer), " ");
        }
    }
}

void append_tile_to_look_table(world_t *world, pos_t *pos, int team_id,
        char **look_table)
{
    char *tile = calloc(1, 1);

    tile_to_str(world, pos, team_id, &tile);
    if (!*look_table[0])
        *look_table[0] = '[';
    *look_table = realloc(*look_table, strlen(*look_table) + strlen(tile) + 3);
    strcat(*look_table, tile);
    (*look_table)[strlen(*look_table) - 1] = ',';
}

int look_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    int look_table_len = 0;
    pos_t current_pos = {player->x, player->y};
    char *look_table = calloc(1, 2);

    for (int i = 0; i <= player->level; i++) {
        for (int j = 0; j < 1 + i * 2; j++) {
            append_tile_to_look_table(world, &current_pos,
                    player->team_id, &look_table);
            next_case(world, &current_pos, player->orientation + 1, 1);
        }
        next_case(world, &current_pos, player->orientation - 1, 2 + i * 2);
        next_case(world, &current_pos, player->orientation, 1);
    }
    look_table_len = strlen(look_table);
    look_table[look_table_len - 1] = ']';
    look_table[look_table_len] = '\n';
    look_table[look_table_len + 1] = 0;
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
    asprintf(&res, "%d\n", world->max_team_size - player_in_team);
    set_response(res);
    return (NO_ERROR);
}

int death_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    remove_player(world, player);
    set_response("dead\n");
    return (NO_ERROR);
}
