/*
** EPITECH PROJECT, 2018
** world_generation.c
** File description:
** generate world
*/

#include <stdlib.h>

#include "map.h"
#include "resources.h"
#include "world.h"
#include "graphical/protocols.h"
#include "error.h"

void generate_resources(resource_t *resources, srv_tile_content_t *tile)
{
    size_t size = 0;

    if (resources == 0x0 || tile == 0x0)
        return;
    while (resources[size++].name != 0x0);
    if (size < MINIMAL_RESOURCES)
        exit_with_error("Not enough resources");
    tile->q0 += (((rand() % 100) <= resources[0].percentage) ? 1 : 0);
    tile->q1 += (((rand() % 100) <= resources[1].percentage) ? 1 : 0);
    tile->q2 += (((rand() % 100) <= resources[2].percentage) ? 1 : 0);
    tile->q3 += (((rand() % 100) <= resources[3].percentage) ? 1 : 0);
    tile->q4 += (((rand() % 100) <= resources[4].percentage) ? 1 : 0);
    tile->q5 += (((rand() % 100) <= resources[5].percentage) ? 1 : 0);
    tile->q6 += (((rand() % 100) <= resources[6].percentage) ? 1 : 0);
}

world_t generate_world(size_t width, size_t height,
        const char *resources_filename)
{
    world_t world = {create_map(width, height),
        parse_resources(resources_filename)};

    for (size_t x = 0 ; x < world.map.width ; x++) {
        for (size_t y = 0 ; y < world.map.height ; y++)
            generate_resources(world.resources, &world.map.tiles[x][y]);
    }
    return (world);
}

void update_world_resources(world_t *world)
{
    for (size_t x = 0 ; x < world->map.width ; x++) {
    for (size_t y = 0 ; y < world->map.height ; y++)
        generate_resources(world->resources, &world->map.tiles[x][y]);
    }
}
