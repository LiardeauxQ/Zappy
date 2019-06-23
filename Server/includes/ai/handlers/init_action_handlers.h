/*
** EPITECH PROJECT, 2018
** init_action_handlers.h
** File description:
** init_action_handlers header
*/

/**
 * \file init_action_handlers.h
 * \brief initialise action functions.
 * \date Jun, 23 2019
 *
 */


#pragma once

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "error.h"
#include "manage_response.h"

#include "ai/protocols.h"

#include "ai/handlers/movement_handlers.h"
#include "ai/handlers/player_info_handlers.h"
#include "ai/handlers/resources_handlers.h"
#include "ai/handlers/elevation_handler.h"
#include "ai/handlers/fork_handler.h"

act_handler_t *init_action_handler(char *command, int limit_cycles,
    uint16_t args_nbr, action_handler_fcnt handler);

void register_action_handler(ahr_t *registrar, act_handler_t *handler);

void init_action_handler_register(ahr_t *reg);
