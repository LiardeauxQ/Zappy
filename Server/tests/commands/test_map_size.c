/*
** EPITECH PROJECT, 2018
** test_map_size.c
** File description:
** test map_size command
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "graphical/commands.h"
#include "graphical/protocols.h"
#include "world.h"
#include "linked_list.h"
#include "unit_tests.h"

Test(send_map_size, simple_test)
{
    world_t world = {0};
    int fd = open("tmp_map_size", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_MAP_SIZE_LEN;
    char result[PKT_HDR_LEN + SRV_MAP_SIZE_LEN + 1] = {0};
    pkt_header_t hdr = {13, PROTOCOL_VERSION, SRV_MAP_SIZE_LEN, 0};
    srv_map_size_t map_size = {34, 34};
    cmd_info_t cmd[] = {{&world, sizeof(world_t)}, {0}};

    cr_assert_neq(fd, -1);
    world.width = 34;
    world.height = 34;
    wrap_graph_protocol_commands(&send_map_size, fd, cmd);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &map_size, SRV_MAP_SIZE_LEN);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
