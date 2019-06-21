/*
** EPITECH PROJECT, 2018
** resources_handlers.h
** File description:
** Resources handlers header
*/

#pragma once

#include "world.h"
#include "manage_response.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"

char *resource_to_string(const enum RESOURCE_NUMBER id, const int quantity,
        resource_t *resources);

enum RESOURCE_NUMBER resource_str_to_id(const char *resource,
        resource_t *resources);

int take_object_handler(world_t *world, player_t *player, const char **args);

int set_down_object_handler(world_t *world, player_t *player,
        const char **args);

int inventory_handler(world_t *world, player_t *player, const char **args);
