/*
** EPITECH PROJECT, 2018
** test_packet_handler.c
** File description:
** test packet_handler functions
*/

#include <criterion/criterion.h>
#include <graphical/packets.h>

Test(packet_handler, simple_init_test)
{
    pkt_handler_t *pkt = init_pkt(0, 1, "Test", 0x0);

    cr_assert_eq(pkt->id, 0);
    cr_assert_eq(pkt->subid, 1);
    cr_assert_str_eq(pkt->name, "Test");
    cr_assert_eq(pkt->id, 0x0);
}

Test(packet_handler, simple_add_packet_test)
{
    phr_t reg = {0};

    cr_assert_eq(add_pkt_info(&reg, init_pkt(0, 1, "Test", 0x0)), &reg);
}

Test(packet_handler, simple_error_test_with_wrong_argument)
{
    cr_assert_eq(add_pkt_info(0x0, init_pkt(0, 1, "Test", 0x0)), 0x0);
}
