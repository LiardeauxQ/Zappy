/*
** EPITECH PROJECT, 2018
** player_info_handlers.c
** File description:
** Player info handlers - Unit Tests
*/

#include <criterion/criterion.h>
#include "ai/handlers/player_info_handlers.h"

Test(look_handler, test_look_handler)
{
    int id = 0;
    world_t world = {0};
    player_t *head = 0x0;

    world.f = 100;
    world.width = 4;
    world.height = 4;
    generate_world(&world, 0x0);
    append(&world.tiles[1][1].players_id, &id);
    add_player(&world, 0);
    head = (player_t *) world.players.head->data;
    head->x = 1;
    head->y = 1;
    look_handler(&world, head, 0x0);
}

Test(connect_nbr_handler, test_connect_nbr_handler)
{
    world_t world = {0};
    player_t *head = 0x0;

    world.f = 100;
    world.width = 4;
    world.height = 4;
    generate_world(&world, 0x0);
    add_player(&world, 0);
    head = (player_t *) world.players.head->data;
    connect_nbr_handler(&world, head, 0x0);
    cr_assert_eq(atoi(get_response()), world.max_team_size - 1);
}

Test(death_handler, test_death_handler)
{
    world_t world = {0};
    player_t *head = 0x0;

    world.f = 100;
    world.width = 4;
    world.height = 4;
    generate_world(&world, 0x0);
    add_player(&world, 0);
    head = (player_t *) world.players.head->data;
    look_handler(&world, head, 0x0);
}
