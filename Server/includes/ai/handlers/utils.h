/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Utils header
*/

/**
 * \file utils.h
 * \brief utils functions.
 * \date Jun, 23 2019
 *
 */

#pragma once

#include "world.h"

player_t *get_player(linked_list_t players, int id);

pos_t *next_case(world_t *world_t, pos_t *pos, int orientation, int inc);

int is_time_limit_reached(const clock_t start, const uint16_t limit_cycles,
        const unsigned int f);
