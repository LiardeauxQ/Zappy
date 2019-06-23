/*
** EPITECH PROJECT, 2018
** test_world_generation.c
** File description:
** test world generation
*/

#include <criterion/criterion.h>
#include <stdlib.h>

#include "world.h"
#include "resources.h"
#include "graphical/protocols.h"
#include "linked_list.h"

Test(generate_resources, simple_test)
{
    resource_t *resources = parse_resources(0x0);
    tile_content_t tile = {0};

    tile.resources = calloc(1, (DEFAULT_RESOURCES_NUMBER + 1) * sizeof(int));
    tile.resources[DEFAULT_RESOURCES_NUMBER] = -1;
    generate_resources(&tile.resources, resources);
    for (int i = 0 ; i < DEFAULT_RESOURCES_NUMBER ; i++) {
        cr_assert(tile.resources[i] >= 0 && tile.resources[i] <= 1);
    }
    free(tile.resources);
}

Test(generate_resources, with_no_parameters)
{
    tile_content_t tile = {0};

    tile.resources = calloc(1, (DEFAULT_RESOURCES_NUMBER + 1) * sizeof(int));
    tile.resources[DEFAULT_RESOURCES_NUMBER] = -1;
    generate_resources(&tile.resources, 0x0);
    for (int i = 0 ; i < DEFAULT_RESOURCES_NUMBER ; i++)
        cr_assert_eq(tile.resources[i], 0);
    free(tile.resources);
}

Test(init_tiles, simple_test)
{
    int width = 3;
    int height = 3;
    tile_content_t **tiles = init_tiles(width, height, 2);

    for (int i = 0 ; i < width ; i++) {
        for (int j = 0 ; j < height ; j++) {
            cr_assert_eq(tiles[i][j].resources[2], -1);
            cr_assert_eq(tiles[i][j].players_id.head, 0x0);
        }
    }
}

Test(init_tiles, null_value_test)
{
    int width = 0;
    int height = 0;
    tile_content_t **tiles = init_tiles(width, height, 2);

    cr_assert_eq(tiles, 0);
}

Test(update_world_resources, simple_test)
{
    int height = 4;
    int width = 4;
    world_t world = {0};
    
    world.width = width;
    world.height = height;
    generate_world(&world, 0x0);
    update_world_resources(&world);
    for (int i = 0 ; i < width ; i++) {
        for (int j = 0 ; j < height ; j++) {
            for (int k = 0 ; k < DEFAULT_RESOURCES_NUMBER ; k++)
                cr_assert(world.tiles[i][j].resources[k] >= 0
                        && world.tiles[i][j].resources[k] <= 2);
        }
    }
}
