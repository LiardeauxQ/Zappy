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

Test(send_map_size, simple_test)
{
    world_t world = {0};
    int fd = open("tmp", O_CREAT | O_RDWR, 0644);
    int magic_num = SENDER_MAGIC_NUM;
    char data[80] = {0};
    char buffer[80] = {0};
    const size_t size = PKT_HDR_LEN + SRV_MAP_SIZE_LEN + 1;
    char result[PKT_HDR_LEN + SRV_MAP_SIZE_LEN + 1] = {0};
    pkt_header_t hdr = {13, PROTOCOL_VERSION, SRV_MAP_SIZE_LEN, 0};
    srv_map_size_t map_size = {34, 34};
    sender_t sender = {&world, sizeof(world_t), fd, 1};

    cr_assert_neq(fd, -1);
    world.width = 34;
    world.height = 34;
    memcpy(data, &magic_num, 4);
    memcpy(data + 4, &sender, sizeof(sender_t));
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &map_size, SRV_MAP_SIZE_LEN);
    send_map_size(data);
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
}
