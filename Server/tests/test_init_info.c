/*
** EPITECH PROJECT, 2018
** test_init_info.c
** File description:
** test init_info functions
*/

#include <criterion/criterion.h>

#include "server.h"

Test(init_info, simple_test)
{
    int ac = 9;
    char *av[] = {"./zappy_server", "-f", "34", "-p", "23", "-x", "5",
        "-y", "5"};
    info_t info = init_info(ac, av);

    cr_assert_eq(info.input.width, 5);
    cr_assert_eq(info.input.height, 5);
    cr_assert_eq(info.input.frequence, 34);
    cr_assert_eq(info.input.port, 23);
    cr_assert_eq(info.game.world.width, 5);
    cr_assert_eq(info.game.world.height, 5);
    cr_assert_eq(info.game.world.tiles[2][2].player_nb, 0);
    cr_assert_eq(info.game.world.tiles[1][3].player_nb, 0);
    cr_assert_eq(info.server_ai.port, 23);
    cr_assert_eq(info.server_graph.port, 24);
}

