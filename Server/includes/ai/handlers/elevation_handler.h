/*
** EPITECH PROJECT, 2018
** movement_handlers.h
** File description:
** Movement handlers header
*/

#pragma once

#include "world.h"
#include "manage_response.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"

int is_enough_users(world_t *world, tile_content_t *tile, player_t *player);

int elevation_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args);
