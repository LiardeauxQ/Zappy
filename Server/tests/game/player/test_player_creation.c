/*
** EPITECH PROJECT, 2018
** test_player_creation.c
** File description:
** test player creation
*/

#include <criterion/criterion.h>
#include <stdlib.h>

#include "world.h"
#include "player.h"

Test(add_player, simple_test)
{
    unsigned int width = 4;
    unsigned int height = 4;
    world_t world = generate_world(width, height, 0, 0x0);

    add_player(&world, 0);
    cr_assert_eq(world.players[0].id, 0);
    cr_assert(world.players[0].x > 0 && world.players[0].x < width);
    cr_assert(world.players[0].y > 0 && world.players[0].y < height);
    cr_assert(world.players[0].direction >= 0
            && world.players[0].direction <= 4);
    cr_assert_eq(world.players[0].level, 0);
    cr_assert_eq(world.players[0].team_id, 0);
}
