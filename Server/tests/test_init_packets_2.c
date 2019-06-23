/*
** EPITECH PROJECT, 2018
** test_init_packets.c
** File description:
** test init_packet functions
*/

#include <criterion/criterion.h>
#include "graphical/packets.h"

Test(init_server_additionals_packets, simple_test)
{
    phr_t reg = {0};

    init_server_additionals_packets(&reg);
    cr_assert_eq(reg.size, 4);
    cr_assert_eq(reg.handlers[0]->id, 35);
    cr_assert_eq(reg.handlers[1]->id, 36);
    cr_assert_eq(reg.handlers[2]->id, 37);
    cr_assert_eq(reg.handlers[3]->id, 40);
}
