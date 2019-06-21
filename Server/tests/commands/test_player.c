/*
** EPITECH PROJECT, 2018
** test_player.c
** File description:
** test player commands
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

Test(send_player_death, simple_test)
{
    int player_num = 34;
    int fd = open("tmp8", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_DEATH_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_DEATH_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_PLAYER_DEATH, PROTOCOL_VERSION,
        SRV_PLAYER_DEATH_LEN, 0};
    srv_player_death_t player = {player_num};
    cmd_info_t cmd[] = {{&player_num, sizeof(int)}, {0}};

    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_player_death, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &player, SRV_PLAYER_DEATH_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}

static linked_list_t init_players(void)
{
    player_t *player = calloc(1, sizeof(player_t));
    linked_list_t list = {0};

    *player = (player_t){1, 2, 3, 4, 4, {0}, 3, 3};
    append(&list, player);
    return (list);
}

Test(send_player_level, simple_test)
{
    world_t world = {0, 0, 0, 0x0, 0x0, init_players(), 0x0};
    int fd = open("tmp9", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_LEVEL_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_LEVEL_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_PLAYER_LEVEL, PROTOCOL_VERSION,
        SRV_PLAYER_LEVEL_LEN, 0};
    clt_player_level_t clt = {1};
    srv_player_level_t lvl = {1, 3};
    cmd_info_t cmd[] = {{&world, sizeof(world)}, {&clt, sizeof(clt)}, {0}};

    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_player_level, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &lvl, SRV_PLAYER_LEVEL_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}

Test(send_player_position, simple_test)
{
    world_t world = {0, 0, 0, 0x0, 0x0, init_players(), 0x0};
    int fd = open("tmp10", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_POS_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_POS_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_PLAYER_POSITION, PROTOCOL_VERSION,
        SRV_PLAYER_POS_LEN, 0};
    clt_player_pos_t clt = {1};
    srv_player_pos_t srv = {1, 3, 3, 4};
    cmd_info_t cmd[] = {{&world, sizeof(world)}, {&clt, sizeof(clt)}, {0}};

    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_player_position, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_PLAYER_POS_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
