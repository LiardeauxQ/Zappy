/*
** EPITECH PROJECT, 2018
** test_player_connection.c
** File description:
** test player connection
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

Test(send_player_connection, simple_test)
{
    int fd = open("tmp_player_connection", O_CREAT | O_RDWR, 0644);
    char buffer[256] = {0};
    const size_t size = PKT_HDR_LEN + SRV_NEW_PLAYER_CONNECT_LEN;
    char result[PKT_HDR_LEN + SRV_NEW_PLAYER_CONNECT_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_NEW_PLAYER_CONNECT, PROTOCOL_VERSION,
        SRV_NEW_PLAYER_CONNECT_LEN, 0};
    srv_new_player_connect_t srv = {1, 2, 3, 2, 3, "test"};
    player_t player = {3, 1, 0, 0, 0, 2, {0}, 2, 3};
    team_t teams[2] = {{1, 0, "test", {0}}, {0}};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[PLAYER_SENDER_POS] = (cmd_info_t){&player, sizeof(player_t)};
    cmd[TEAMS_SENDER_POS] = (cmd_info_t){teams, 2 * sizeof(team_t)};
    cr_assert_neq(fd, -1);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_PLAYER_INVENTORY_LEN);
    wrap_graph_protocol_commands(&send_player_connection, fd, cmd);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
