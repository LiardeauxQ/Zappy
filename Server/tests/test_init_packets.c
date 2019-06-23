/*
** EPITECH PROJECT, 2018
** test_init_packets.c
** File description:
** test init_packet functions
*/

#include <criterion/criterion.h>
#include "graphical/packets.h"

Test(init_client_packets, simple_test)
{
    phr_t reg = {0};

    init_client_packets(&reg);
    cr_assert_eq(reg.size, 11);
}

Test(init_client_packets, test_with_no_value)
{
    phr_t reg = {0};

    cr_assert_eq(init_client_packets(&reg), 0);
    cr_assert_eq(init_server_environnements_packets(NULL), -1);
    cr_assert_eq(init_server_actions_packets1(NULL), -1);
    cr_assert_eq(init_server_actions_packets2(NULL), -1);
    cr_assert_eq(init_server_additionals_packets(NULL), -1);
}

Test(init_server_environnements_packets, simple_test)
{
    phr_t reg = {0};

    init_server_environnements_packets(&reg);
    cr_assert_eq(reg.size, 10);
    cr_assert_str_eq(reg.handlers[0]->name, "SRV_PROTOCOL_ADDONS");
    cr_assert_str_eq(reg.handlers[1]->name, "SRV_MAP_SIZE");
    cr_assert_str_eq(reg.handlers[2]->name, "SRV_TILE_CONTENT");
}

Test(init_server_actions_packets1, simple_test)
{
    phr_t reg = {0};

    init_server_actions_packets1(&reg);
    cr_assert_eq(reg.size, 5);
    cr_assert_eq(reg.handlers[0]->subid, 0);
    cr_assert_eq(reg.handlers[1]->subid, 0);
    cr_assert_eq(reg.handlers[2]->subid, 0);
    cr_assert_eq(reg.handlers[3]->subid, 0);
}

Test(init_server_actions_packets2, simple_test)
{
    phr_t reg = {0};

    init_server_actions_packets2(&reg);
    cr_assert_eq(reg.size, 8);
    cr_assert_str_eq(reg.handlers[0]->name, "SRV_PLAYER_DEATH");
    cr_assert_str_eq(reg.handlers[1]->name, "SRV_EGG_LAYED");
    cr_assert_str_eq(reg.handlers[2]->name, "SRV_EGG_HATCHING");
}