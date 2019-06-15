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
    world_t world = generate_world(20, 20, 0x0);

    srand(0x0);
    add_player(&world, "test");
    cr_assert_eq(world.players[0].player_num, 0);
    cr_assert_eq(world.players[0].x, 10);
    cr_assert_eq(world.players[0].y, 11);
    cr_assert_eq(world.players[0].orientation, 3);
    cr_assert_eq(world.players[0].level, 0);
    cr_assert_str_eq(world.players[0].team_name, "test");
}
