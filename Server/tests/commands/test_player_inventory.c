/*
** EPITECH PROJECT, 2018
** test_player_inventory.c
** File description:
** test player's inventory
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

    *player = (player_t){3, 1, 2, 4, {0, 1, 2, 3, 4, 5, 6}, 3, 3, 4, 0};
    append(&list, player);
    return (list);
}

Test(send_player_inventory, simple_test)
{
    world_t world = {0, 0, 0, 0, 0x0, 0x0, init_players(), 0x0};
    int fd = open("tmp11", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_PLAYER_INVENTORY_LEN;
    char result[PKT_HDR_LEN + SRV_PLAYER_INVENTORY_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_PLAYER_INVENTORY, PROTOCOL_VERSION,
        SRV_PLAYER_INVENTORY_LEN, 0};
    struct clt_player_inventory clt = {1};
    srv_player_inventory_t inv = {1, 3, 3, 0, 1, 2, 3, 4, 5, 6};
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[WORLD_SENDER_POS] = (cmd_info_t){&world, sizeof(world)};
    cmd[CUSTOM_SENDER_POS] = (cmd_info_t){&clt, sizeof(clt)};
    cr_assert_neq(fd, -1);
    wrap_graph_protocol_commands(&send_player_inventory, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &inv, SRV_PLAYER_INVENTORY_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
