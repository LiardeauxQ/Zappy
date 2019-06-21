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
    player_t *head = 0x0;

    world.f = 100;
    add_player(&world, 0);
    head = (player_t *) world.players.head;
    head->x = 1;
    head->y = 1;
    head->orientation = EAST;
    forward_move_handler(&world, head, 0x0);
    cr_assert_eq(head->x, 2);
    cr_assert_eq(strcmp(get_response(), "ok"), 0);
}

Test(left_move_handler, test_left_move_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *head = 0x0;

    world.f = 100;
    add_player(&world, 0);
    head = (player_t *) world.players.head;
    head->orientation = EAST;
    left_move_handler(&world, head, 0x0);
    cr_assert_eq(head->orientation, NORTH);
    cr_assert_eq(strcmp(get_response(), "ok"), 0);
}

Test(right_move_handler, test_right_move_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *head = 0x0;

    world.f = 100;
    add_player(&world, 0);
    head = (player_t *) world.players.head;
    head->orientation = EAST;
    right_move_handler(&world, head, 0x0);
    cr_assert_eq(head->orientation, SOUTH);
    cr_assert_eq(strcmp(get_response(), "ok"), 0);
}
