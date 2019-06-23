/*
** EPITECH PROJECT, 2018
** resources_handlers.c
** File description:
** Resources handlers - Unit Tests
*/

#include <criterion/criterion.h>
#include "ai/handlers/resources_handlers.h"

world_t *wrap_action_handlers();

Test(take_object_handler, test_take_object_handler)
{
    const char *args[] = {"linemate", NULL};
    world_t *world = wrap_action_handlers();
    player_t *player = 0x0;

    player = (player_t *) world->players.head->data;
    player->x = 1;
    player->y = 1;
    world->tiles[1][1].resources[1] = 1;
    take_object_handler(world, player, args);
    cr_assert_eq(player->resources[1], 1);
    cr_assert_eq(world->tiles[1][1].resources[1], 0);
    cr_assert_eq(strcmp(get_response(), "ok\n"), 0);
}

Test(set_down_object_handler, test_set_down_object_handler)
{
    const char *args[] = {"linemate", NULL};
    world_t *world = wrap_action_handlers();
    player_t *player = 0x0;
    int old_resources_nbr_on_tile = 0;

    player = (player_t *) world->players.head->data;
    player->x = 1;
    player->y = 1;
    player->resources[1] = 1;
    old_resources_nbr_on_tile = world->tiles[1][1].resources[1];
    set_down_object_handler(world, player, args);
    cr_assert_eq(player->resources[1], 0);
    cr_assert_eq(world->tiles[1][1].resources[1],
        old_resources_nbr_on_tile + 1);
    cr_assert_eq(strcmp(get_response(), "ok\n"), 0);
}

Test(inventory_handler, test_inventory_handler)
{
    world_t *world = wrap_action_handlers();
    player_t *player = 0x0;

    player = (player_t *) world->players.head->data;
    player->x = 1;
    player->y = 1;
    player->resources[1] = 1;
    player->resources[2] = 5;
    player->resources[5] = 3;
    inventory_handler(world, player, 0x0);
    cr_assert_eq(strcmp(get_response(), "[linemate 1, deraumere 5, sibur 0, "
        "mendiane 0, phiras 3, thystame 0, custom 0]\n"), 0);
}
