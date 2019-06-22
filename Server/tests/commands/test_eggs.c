/*
** EPITECH PROJECT, 2018
** test_eggs.c
** File description:
** test egg commands
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

Test(send_laying_egg, simple_test)
{
    int player_num = 34;
    int fd = open("tmp_laying_egg", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_LAYING_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_EGG_LAYING_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_EGG_LAYING, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_LAYING_LEN, 0};
    srv_player_egg_laying_t egg = {player_num};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[INT_SENDER_POS] = (cmd_info_t){&player_num, sizeof(int)};
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_laying_egg, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &egg, SRV_PLAYER_EGG_LAYING_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}

Test(send_layed_egg, simple_test)
{
    int egg_num = 34;
    int fd = open("tmp_layed_egg", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_LAYED_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_EGG_LAYED_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_EGG_LAYED, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_LAYED_LEN, 0};
    srv_player_egg_layed_t egg = {23, 34, 34, 34};
    player_t player = {0, 23, 1, 10, 0, 1, {0}, 34, 34};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[PLAYER_SENDER_POS] = (cmd_info_t){&player, sizeof(player_t)};
    cmd[INT_SENDER_POS] = (cmd_info_t){&egg_num, sizeof(int)};
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_layed_egg, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &egg, SRV_PLAYER_EGG_LAYED_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}

Test(send_hatching_egg, simple_test)
{
    int egg_num = 34;
    int fd = open("tmp_hatching_egg", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_HATCHING_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_EGG_HATCHING_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_EGG_HATCHING, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_HATCHING_LEN, 0};
    srv_player_egg_hatching_t egg = {34};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[INT_SENDER_POS] = (cmd_info_t){&egg_num, sizeof(int)};
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_hatching_egg, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &egg, SRV_PLAYER_EGG_HATCHING_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}

Test(send_egg_connection, simple_test)
{
    int egg_num = 34;
    int fd = open("tmp_egg_connection", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_CONNECTION_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_EGG_CONNECTION_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_PLAYER_CONNECT_EGG, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_CONNECTION_LEN, 0};
    srv_player_egg_connection_t egg = {34};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[INT_SENDER_POS] = (cmd_info_t){&egg_num, sizeof(int)};
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_egg_connection, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &egg, SRV_PLAYER_EGG_CONNECTION_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}

Test(send_egg_hatched_death, simple_test)
{
    int egg_num = 34;
    int fd = open("tmp_egg_hatched", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_HATCHED_EGG_DEATH_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_EGG_CONNECTION_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_PLAYER_DEATH_EGG, PROTOCOL_VERSION,
        SRV_HATCHED_EGG_DEATH_LEN, 0};
    srv_player_egg_hatching_t egg = {34};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[INT_SENDER_POS] = (cmd_info_t){&egg_num, sizeof(int)};
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_egg_hatched_death, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &egg, SRV_HATCHED_EGG_DEATH_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
