/*
** EPITECH PROJECT, 2018
** fork_handler.h
** File description:
** fork handler header
*/

#pragma once

#include "world.h"
#include "manage_response.h"
#include "ai/protocols.h"

int hatch(world_t *world);

int fork_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args);
