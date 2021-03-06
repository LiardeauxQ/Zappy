/*
** EPITECH PROJECT, 2018
** elevation_handlers.c
** File description:
** Elevation handlers - Unit Tests
*/

#include <criterion/criterion.h>
#include "ai/handlers/elevation_handler.h"

world_t *wrap_action_handlers();

Test(elevation_handler, test_elevation_handler)
{
    world_t *world = wrap_action_handlers();
    player_t *player1 = 0x0;
    player_t *player2 = 0x0;

    player1 = (player_t *) world->players.head->data;
    player1->x = 1;
    player1->y = 1;
    player2 = (player_t *) world->players.head->next->data;
    append(&world->tiles[1][1].players_id, &player1->id);
    append(&world->tiles[1][1].players_id, &player2->id);
    world->tiles[1][1].resources[1] = 1;
    elevation_handler(world, player1, 0x0);
    cr_assert_eq(strcmp(get_response(), "Elevation underway\n"), 0);
}
