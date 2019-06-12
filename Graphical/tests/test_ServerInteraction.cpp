/*
** EPITECH PROJECT, 2018
** ServerInteraction.cpp
** File description:
** ServerInteraction tests
*/

#include <criterion/criterion.h>
#include "ServerInteraction.hpp"
#include <stdio.h>

Test(ServerInteraction, simple_test)
{
    pkt_header_t hdr = {0, 0, 0, 0};
    communication::ServerInteraction interaction;

    interaction.requestMapSize();
    cr_assert_eq(hdr.id, CLT_MAP_SIZE);
    cr_assert_eq(hdr.version, PROTOCOL_VERSION);
    cr_assert_eq(hdr.size, 0);
    cr_assert_eq(hdr.subid, 0);
}
