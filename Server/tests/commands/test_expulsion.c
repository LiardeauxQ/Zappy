/*
** EPITECH PROJECT, 2018
** test_expulsion.c
** File description:
** test expulsion command
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

Test(send_player_expulsion, simple_test)
{
    int player_num = 34;
    int fd = open("tmp_expulsion", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_EXPULSION_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_EXPULSION_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_EXPULSION, PROTOCOL_VERSION,
        SRV_PLAYER_EXPULSION_LEN, 0};
    srv_player_expulsion_t player = {34};
    cmd_info_t cmd[] = {{&player_num, sizeof(int)}, {0}};

    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_player_expulsion, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &player, SRV_PLAYER_EXPULSION_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
