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

Test(generate_resources, simple_test)
{
    resource_t *resources = parse_resources(0x0);
    srv_tile_content_t tile = {0};

    srand(0x0);
    generate_resources(resources, &tile);
    cr_assert_eq(tile.q0, 1);
    cr_assert_eq(tile.q1, 0);
    cr_assert_eq(tile.q2, 1);
    cr_assert_eq(tile.q3, 0);
    cr_assert_eq(tile.q4, 0);
    cr_assert_eq(tile.q5, 0);
    cr_assert_eq(tile.q6, 1);
    free_resources(resources);
}

Test(generate_resources, with_no_parameters)
{
    srv_tile_content_t tile = {0};

    generate_resources(0x0, &tile);
    cr_assert_eq(tile.q0, 0);
    cr_assert_eq(tile.q1, 0);
    cr_assert_eq(tile.q2, 0);
    cr_assert_eq(tile.q3, 0);
    cr_assert_eq(tile.q4, 0);
    cr_assert_eq(tile.q5, 0);
    cr_assert_eq(tile.q6, 0);
}
