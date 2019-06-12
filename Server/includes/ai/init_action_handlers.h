/*
** EPITECH PROJECT, 2018
** init_action_handlers.h
** File description:
** init_action_handlers header
*/

#pragma once

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "protocols.h"
#include "error.h"

act_handler_t *init_action_handler(char *command, uint16_t limit_cycles,
    uint16_t args_nbr, action_handler_fcnt handler);

void register_action_handler(ahr_t *registrar, act_handler_t *handler);

void init_action_handler_register(ahr_t *reg);
