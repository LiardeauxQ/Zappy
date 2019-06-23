/*
** EPITECH PROJECT, 2018
** elevation_handler.h
** File description:
** Elevation handlers header
*/

#pragma once

#include "world.h"
#include "client.h"
#include "manage_response.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"
#include "graphical/commands.h"

#define ELEVATION_TIME 300

void elevate(int client_fd, world_t *world, player_t *player);

int is_enough_users(world_t *world, tile_content_t *tile, player_t *player);

int elevation_handler(world_t *world, player_t *player, const char **args);
