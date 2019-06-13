/*
** EPITECH PROJECT, 2018
** player_info_handlers.h
** File description:
** Player informations handlers header
*/

#pragma once

#include "ai/player.h"
#include "ai/protocols.h"
#include "ai/handlers/utils.h"

int look_handler(player_t *player, const uint16_t limit_cycles,
        const char **args);
int connect_nbr_handler(player_t *player, const uint16_t limit_cycles,
        const char **args);
int death_handler(player_t *player, const uint16_t limit_cycles,
        const char **args);
