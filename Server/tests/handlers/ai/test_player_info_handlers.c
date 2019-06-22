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
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *player = 0x0;

    add_player(&world, 0);
    player = (player_t *) world.players.head->data;
    player->x = 1;
    player->y = 1;
    append(&world.tiles[1][1].players_id, &player->id);
    look_handler(&world, player, 0x0);
}

Test(connect_nbr_handler, test_connect_nbr_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *player = 0x0;

    add_player(&world, 0);
    player = (player_t *) world.players.head->data;
    connect_nbr_handler(&world, player, 0x0);
    cr_assert_eq(atoi(get_response()), world.max_team_size - 1);
}

Test(death_handler, test_death_handler)
{
    int player_id = 0;
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *player = 0x0;

    add_player(&world, 0);
    player = (player_t *) world.players.head->data;
    player_id = player->id;
    cr_assert_neq(get_player(world.players, player_id), 0);
    death_handler(&world, player, 0x0);
    cr_assert_eq(get_player(world.players, player_id), 0);
}
