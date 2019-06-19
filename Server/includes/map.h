/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** handle map
*/

#pragma once

#include "graphical/protocols.h"

typedef struct map_s {
    unsigned int width;
    unsigned int height;
    srv_tile_content_t **tiles;
} map_t;

/* create_map.c */

map_t create_map(unsigned int width, unsigned int height);
