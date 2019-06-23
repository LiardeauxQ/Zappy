/*
** EPITECH PROJECT, 2018
** movement_handlers.h
** File description:
** Movement handlers header
*/

/**
 * \file movement_handlers.h
 * \brief handle mouvement functions.
 * \date Jun, 23 2019
 *
 */

#pragma once

#include "world.h"
#include "client.h"
#include "manage_response.h"
#include "manage_graph_clients.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"
#include "graphical/commands.h"

void move_player(world_t *world, player_t *player, int x, int y);

int forward_move_handler(world_t *world, player_t *player, const char **args);

int left_move_handler(world_t *world, player_t *player, const char **args);

int right_move_handler(world_t *world, player_t *player, const char **args);
