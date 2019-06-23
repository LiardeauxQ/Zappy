/*
** EPITECH PROJECT, 2018
** fork_handler.h
** File description:
** fork handler header
*/

/**
 * \file fork_handler.h
 * \brief forkn functions.
 * \date Jun, 23 2019
 *
 */

#pragma once

#include "world.h"
#include "client.h"
#include "manage_response.h"
#include "graphical/commands.h"
#include "manage_graph_clients.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"

#define HATCH_TIME 600

void hatch(world_t *world, player_t *player);

int fork_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args);
