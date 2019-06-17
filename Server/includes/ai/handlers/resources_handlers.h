/*
** EPITECH PROJECT, 2018
** resources_handlers.h
** File description:
** Resources handlers header
*/

#pragma once

#include "ai/player.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"

char *resource_to_string(const enum RESOURCE_ID id, const int quantity);

enum RESOURCE_ID resource_str_to_id(const char *resource);

int take_object_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char **args);

int set_down_object_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char **args);

int inventory_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char **args);
