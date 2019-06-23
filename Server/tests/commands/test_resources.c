/*
** EPITECH PROJECT, 2018
** test_resources.c
** File description:
** test resources
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

Test(send_resource_drop, simple_test)
{
    int fd = open("tmp_resource_drop", O_CREAT | O_RDWR, 0644);
    char buffer[256] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_RESOURCE_DROPPED_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_RESOURCE_DROPPED_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_RESOURCE_DROP, PROTOCOL_VERSION,
        SRV_PLAYER_RESOURCE_DROPPED_LEN, 0};
    int player_num = 34;
    enum RESOURCE_NUMBER resource = 1;
    srv_player_resource_dropped_t srv = {34, 1};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[INT_SENDER_POS] = (cmd_info_t){&player_num, sizeof(int)};
    cmd[CUSTOM_SENDER_POS] = (cmd_info_t){&resource,
        sizeof(enum RESOURCE_NUMBER)};
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_resource_drop, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_PLAYER_RESOURCE_DROPPED_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}

Test(send_resource_collect, simple_test)
{
    int fd = open("tmp_resource_collect", O_CREAT | O_RDWR, 0644);
    char buffer[256] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_RESOURCE_COLLECTED_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_RESOURCE_COLLECTED_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_RESOURCE_COLLECT, PROTOCOL_VERSION,
        SRV_PLAYER_RESOURCE_COLLECTED_LEN, 0};
    int player_num = 34;
    enum RESOURCE_NUMBER resource = 1;
    srv_player_resource_dropped_t srv = {34, 1};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[INT_SENDER_POS] = (cmd_info_t){&player_num, sizeof(int)};
    cmd[CUSTOM_SENDER_POS] = (cmd_info_t){&resource,
        sizeof(enum RESOURCE_NUMBER)};
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_resource_collect, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_PLAYER_RESOURCE_COLLECTED_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
