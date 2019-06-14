/*
** EPITECH PROJECT, 2018
** name
** File description:
** test init_packet functions
*/

#include <criterion/criterion.h>
#include "graphical/packets.h"

Test(init_packet, simple_client_packets_test)
{
    phr_t reg = {0};

    init_client_packets(&reg);
    cr_assert_eq(reg.size, 11);
}

Test(init_packet, error_test_with_no_value)
{
    phr_t reg = {0};

    cr_assert_eq(init_client_packets(&reg), 0);
    cr_assert_eq(init_server_environnements_packets(NULL), -1);
    cr_assert_eq(init_server_actions_packets(NULL), -1);
    cr_assert_eq(init_server_additionals_packets(NULL), -1);
}

Test(init_packet, simple_environnements_packets_test)
{
    phr_t reg = {0};

    init_server_environnements_packets(&reg);
    cr_assert_eq(reg.size, 10);
    cr_assert_str_eq(reg.handlers[0]->name, "SRV_PROTOCOL_ADDONS");
    cr_assert_str_eq(reg.handlers[1]->name, "SRV_MAP_SIZE");
    cr_assert_str_eq(reg.handlers[2]->name, "SRV_TILE_CONTENT");
}

Test(init_packet, simple_server_actions_packets_test)
{
    phr_t reg = {0};

    init_server_actions_packets(&reg);
    cr_assert_eq(reg.size, 13);
    cr_assert_eq(reg.handlers[0]->subid, 0);
    cr_assert_eq(reg.handlers[1]->subid, 0);
    cr_assert_eq(reg.handlers[2]->subid, 0);
    cr_assert_eq(reg.handlers[3]->subid, 0);
}

Test(init_packet, simple_server_additional_packets_test)
{
    phr_t reg = {0};

    init_server_additionals_packets(&reg);
    cr_assert_eq(reg.size, 4);
    cr_assert_eq(reg.handlers[0]->id, 35);
    cr_assert_eq(reg.handlers[1]->id, 36);
    cr_assert_eq(reg.handlers[2]->id, 37);
    cr_assert_eq(reg.handlers[3]->id, 40);
}
