/*
** EPITECH PROJECT, 2018
** test_broadcast.c
** File description:
** test broadcast
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

Test(send_broadcast, simple_test)
{
    char msg[LONG_MSG_LEN] = {"this is a test"};
    int player_num = 22;
    int fd = open("tmp_broadcast", O_CREAT | O_RDWR, 0644);
    char buffer[256] = {0};
    const size_t size = PKT_HDR_LEN + SRV_BROADCAST_MSG_LEN;
    char result[PKT_HDR_LEN + SRV_BROADCAST_MSG_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_BROADCAST, PROTOCOL_VERSION,
        SRV_BROADCAST_MSG_LEN, 0};
    srv_broadcast_msg_t srv = {22, {0}};
    cmd_info_t cmd[] = {{msg, sizeof(msg)}, {&player_num, sizeof(int)}, {0}};

    strcpy(srv.message, msg);
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_broadcast, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_BROADCAST_MSG_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
