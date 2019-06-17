/*
** EPITECH PROJECT, 2018
** world.h
** File description:
** world generation header
*/

#pragma once

#include "map.h"
#include "resources.h"

struct world_s {
    map_t map;
    resource_t *resources;
};

typedef struct world_s world_t;

void generate_resources(resource_t *resources, srv_tile_content_t *tile);
world_t generate_world(size_t width, size_t height,
    const char *resources_filename);
void update_world(world_t *world);
