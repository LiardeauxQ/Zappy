/*
** EPITECH PROJECT, 2018
** movement_handlers.h
** File description:
** Movement handlers header
*/

#pragma once

#include "world.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"

int forward_move_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char **args);

int left_move_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char **args);

int right_move_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char **args);
