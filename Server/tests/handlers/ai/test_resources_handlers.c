/*
** EPITECH PROJECT, 2018
** resources_handlers.c
** File description:
** Resources handlers - Unit Tests
*/

#include <criterion/criterion.h>
#include "ai/handlers/resources_handlers.h"

Test(take_object_handler, test_take_object_handler)
{
    const char *args[] = {"Linemate", NULL};
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *head = 0x0;

    world.f = 100;
    add_player(&world, 0);
    head = (player_t *) world.players.head;
    head->x = 1;
    head->y = 1;
    world.tiles[1][1].resources[1] = 1;
    take_object_handler(&world, head, 100, args);
    cr_assert_eq(head->resources[1], 1);
    cr_assert_eq(world.tiles[1][1].resources[1], 0);
}
