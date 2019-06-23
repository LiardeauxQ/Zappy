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
    world_t world = {0};
    player_t *player = 0x0;

    world.width = width;
    world.height = height;
    generate_world(&world, 0x0);
    add_player(&world, 0);
    player = (player_t*) world.players.head->data;
    cr_assert_eq(player->id, 0);
    cr_assert(player->x > 0 && player->x < width);
    cr_assert(player->y > 0 && player->y < height);
    cr_assert(player->orientation >= 0
            && player->orientation <= 4);
    cr_assert_eq(player->level, 1);
    cr_assert_eq(player->team_id, 0);
}
