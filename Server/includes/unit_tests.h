/*
** EPITECH PROJECT, 2018
** unit_tests.h
** File description:
** unit_tests header
*/

/**
 * \file unit_tests.h
 * \brief unit_tests functions.
 * \date Jun, 23 2019
 *
 */

#pragma once

#include "world.h"
#include "graphical/protocols.h"

struct command_info {
    void *data;
    size_t size;
};

typedef struct command_info cmd_info_t;

void wrap_graph_protocol_commands(data_handler handler, int fd,
        const cmd_info_t *cmd);
