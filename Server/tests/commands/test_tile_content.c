/*
** EPITECH PROJECT, 2018
** test_tile_content.c
** File description:
** test tile content
*/

#include <criterion/criterion.h>
#include <fcntl.h>
#include <unistd.h>

#include "graphical/commands.h"
#include "world.h"
#include "linked_list.h"
#include "unit_tests.h"

Test(send_tile_content, simple_test)
{
    size_t size = PKT_HDR_LEN + SRV_TILE_CONTENT_LEN;
    int ressources[DEFAULT_RESOURCES_NUMBER + 1] = {0, 1, 2, 3, 4, 5, 6, -1};
    int player_nb = 9;
    int fd = open("tmp", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    clt_tile_content_t pos = {0, 0};
    char result[PKT_HDR_LEN + SRV_TILE_CONTENT_LEN + 1] = {0};
    pkt_header_t hdr = {14, PROTOCOL_VERSION, SRV_TILE_CONTENT_LEN, 0};
    srv_tile_content_t tile = {0, 0, 0, 1, 2, 3, 4, 5, 6, player_nb};
    world_t world = {1, 1, 0, init_tiles(1, 1, 8), 0x0, {0}};
    cmd_info_t cmd[] = {{&world, sizeof(world_t)}, {&pos, sizeof(pos)}, {0}};

    cr_assert_neq(fd, -1);
    world.tiles[0][0].resources = ressources;
    world.tiles[0][0].player_nb = player_nb;
    wrap_graph_protocol_commands(&send_tile_content, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &tile, SRV_TILE_CONTENT_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
}

Test(convert_to_srv_tile_content, simple_test)
{
    int ressources[8] = {1, 2, 3, 4, 5, 6, 7, -1};
    linked_list_t list = {0};
    tile_content_t tile = {ressources, list, 23};
    int x = 3;
    int y = 3;
    srv_tile_content_t srv_tile = convert_to_srv_tile_content(&tile, x, y);

    cr_assert_eq(srv_tile.x, (unsigned int)x);
    cr_assert_eq(srv_tile.y, (unsigned int)y);
    cr_assert_eq(srv_tile.q0, (unsigned int)ressources[0]);
    cr_assert_eq(srv_tile.q1, (unsigned int)ressources[1]);
    cr_assert_eq(srv_tile.q2, (unsigned int)ressources[2]);
    cr_assert_eq(srv_tile.q3, (unsigned int)ressources[3]);
    cr_assert_eq(srv_tile.q4, (unsigned int)ressources[4]);
    cr_assert_eq(srv_tile.q5, (unsigned int)ressources[5]);
    cr_assert_eq(srv_tile.q6, (unsigned int)ressources[6]);
    cr_assert_eq(srv_tile.players, (unsigned int)tile.player_nb);
}
