/*
** EPITECH PROJECT, 2018
** test_incantation.c
** File description:
** test incantation commands
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "graphical/commands.h"
#include "graphical/protocols.h"
#include "world.h"
#include "linked_list.h"
#include "unit_tests.h"

static linked_list_t init_players(void)
{
    player_t *player = calloc(1, sizeof(player_t));
    linked_list_t list = {0};

    *player = (player_t){1, 2, 3, 4, 4, {0}, 3, 3};
    append(&list, player);
    return (list);
}

Test(send_incantation_start, simple_test)
{
    world_t world = {0, 0, 0, 0x0, 0x0, init_players(), 0x0};
    player_t plyr = {1, 2, 3, 4, 4, {0}, 3, 3};
    int fd = open("tmp_incantation_start", O_CREAT | O_RDWR, 0644);
    char buffer[256] = {0};
    const size_t size = PKT_HDR_LEN + SRV_START_INCANTATION_LEN;
    char result[PKT_HDR_LEN + SRV_START_INCANTATION_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_INCANTATION_START, PROTOCOL_VERSION,
        SRV_START_INCANTATION_LEN, 0};
    srv_start_incantation_t srv = {3, 3, 3, {0}};
    cmd_info_t cmd[] = {{&world, sizeof(world)}, {&plyr, sizeof(plyr)}, {0}};

    srv.players[0] = 1;
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_incantation_start, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_START_INCANTATION_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}

Test(send_incantation_end, simple_test)
{
    int fd = open("tmp_incantation_end", O_CREAT | O_RDWR, 0644);
    char buffer[256] = {0};
    const size_t size = PKT_HDR_LEN + SRV_END_INCANTATION_LEN;
    char result[PKT_HDR_LEN + SRV_END_INCANTATION_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_INCANTATION_END, PROTOCOL_VERSION,
        SRV_END_INCANTATION_LEN, 0};
    srv_end_incantation_t srv = {3, 3, 3};
    cmd_info_t cmd[] = {{&srv, sizeof(srv)}, {0}};

    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_incantation_end, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_END_INCANTATION_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
