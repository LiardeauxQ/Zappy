/*
** EPITECH PROJECT, 2018
** movement_handlers.c
** File description:
** Movement handlers - Unit Tests
*/

#include <criterion/criterion.h>
#include "ai/handlers/movement_handlers.h"

Test(forward_move_handler, test_forward_move_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);

    add_player(&world, 0);
    world.f = 100;
    world.players[0].x = 1;
    world.players[0].y = 1;
    world.players[0].orientation = EAST;
    forward_move_handler(&world, &world.players[0], 100, 0x0);
    cr_assert_eq(world.players[0].x, 2);
}

Test(left_move_handler, test_left_move_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);

    add_player(&world, 0);
    world.f = 100;
    world.players[0].orientation = EAST;
    left_move_handler(&world, &world.players[0], 100, 0x0);
    cr_assert_eq(world.players[0].orientation, NORTH);
}

Test(right_move_handler, test_right_move_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);

    add_player(&world, 0);
    world.f = 100;
    world.players[0].orientation = EAST;
    right_move_handler(&world, &world.players[0], 100, 0x0);
    cr_assert_eq(world.players[0].orientation, SOUTH);
}
