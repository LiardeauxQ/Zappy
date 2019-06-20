/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Utils header
*/

#pragma once

#include "world.h"

player_t *get_player(linked_list_t players, unsigned int id);

size_t *next_case(world_t *world_t, size_t *coords, int orientation, int inc);

int is_time_limit_passed(const clock_t start, const uint16_t limit_cycles,
        const unsigned int f);
