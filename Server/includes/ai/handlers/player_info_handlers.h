/*
** EPITECH PROJECT, 2018
** player_info_handlers.h
** File description:
** Player informations handlers header
*/

#pragma once

#include "world.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"

char *tile_to_str(world_t *world, size_t *coords, int current_player_id);

void append_tile_to_look_table(char **look_table, char *tile);

int look_handler(world_t *world, player_t *player, const uint16_t limit_cycles,
        const char **args);

int connect_nbr_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char **args);

int death_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char **args);
