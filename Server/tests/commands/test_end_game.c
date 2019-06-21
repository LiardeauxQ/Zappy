/*
** EPITECH PROJECT, 2018
** test_end_game.c
** File description:
** test end game command
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

Test(send_end_game, simple_test)
{
    int fd = open("tmp_end_game", O_CREAT | O_RDWR, 0644);
    char buffer[256] = {0};
    const size_t size = PKT_HDR_LEN + SRV_END_GAME_LEN;
    char result[PKT_HDR_LEN + SRV_END_GAME_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_END_GAME, PROTOCOL_VERSION,
        SRV_END_GAME_LEN, 0};
    srv_end_game_t srv = {"Winning team"};
    cmd_info_t cmd[] = {{srv.winning_team, sizeof(srv.winning_team)}, {0}};

    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_end_game, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_END_GAME_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
