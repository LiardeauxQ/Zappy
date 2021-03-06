/*
** EPITECH PROJECT, 2018
** player_info_handlers.h
** File description:
** Player informations handlers header
*/

/**
 * \file player_info_handlers.h
 * \brief handle player informations functions.
 * \date Jun, 23 2019
 *
 */

#pragma once

#include "world.h"
#include "manage_response.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"
#include "graphical/commands.h"

void tile_to_str(world_t *world, pos_t *pos, char **str);

void append_tile_to_look_table(world_t *world, pos_t *pos, char **look_table);

int look_handler(world_t *world, player_t *player, const char **args);

int connect_nbr_handler(world_t *world, player_t *player, const char **args);

int death_handler(world_t *world, player_t *player, const char **args);
