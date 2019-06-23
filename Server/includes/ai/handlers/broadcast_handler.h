/*
** EPITECH PROJECT, 2018
** broadcast_handler.h
** File description:
** Broadcast handlers header
*/

#pragma once

#include "world.h"
#include "client.h"
#include "manage_response.h"
#include "manage_graph_clients.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"
#include "graphical/commands.h"

void broadcast(client_t (*clients)[MAX_CLIENT], world_t *world,
        player_t *player);

int getBroadcastTile(world_t *world, player_t *src_player, player_t *dest_player);

int broadcast_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args);
