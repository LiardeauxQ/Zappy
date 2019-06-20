/*
** EPITECH PROJECT, 2018
** handle_tile_content.c
** File description:
** handle tile content
*/

#include <string.h>
#include <unistd.h>

#include "graphical/commands.h"
#include "graphical/protocols.h"
#include "world.h"

srv_tile_content_t convert_to_srv_tile_content(tile_content_t *tile,
        const unsigned int x, const unsigned int y)
{
    srv_tile_content_t content = {0};
    size_t size = 0;

    while (tile->resources[size++] != -1);
    if (size < DEFAULT_RESOURCES_NUMBER)
        return (content);
    content.x = x;
    content.y = y;
    content.q0 = tile->resources[0];
    content.q1 = tile->resources[1];
    content.q2 = tile->resources[2];
    content.q3 = tile->resources[3];
    content.q4 = tile->resources[4];
    content.q5 = tile->resources[5];
    content.q6 = tile->resources[6];
    content.players = tile->player_nb;
    return (content);
}

int get_tile_content(const void __attribute__((unused)) *data)
{
    /*sender_t *senders = get_senders_from_data(data);
    size_t size = count_senders(senders);

    if (size != 2)
        return (-1);
    send_map_content(data);
    free(senders);*/
    return (0);
}

static void write_map_tile_content(tile_content_t *tile,
        const unsigned int x, const unsigned int y, const int sockfd)
{
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_TILE_CONTENT_LEN;
    pkt_header_t hdr = {SRV_TILE_CONTENT, PROTOCOL_VERSION,
        SRV_TILE_CONTENT_LEN, 0};
    srv_tile_content_t srv_content = {0};

    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    srv_content = convert_to_srv_tile_content(tile, x, y);
    memcpy(to_write + PKT_HDR_LEN, &srv_content, SRV_TILE_CONTENT_LEN);
    write(sockfd, to_write, size);
}

int send_tile_content(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    size_t size = count_senders(senders);
    world_t *world = 0x0;
    unsigned int *x = 0;
    unsigned int *y = 0;

    if (size != 2)
        return (-1);
    x = (unsigned int*)(senders[1].data);
    y = (unsigned int*)(senders[1].data + sizeof(unsigned int));
    world = (world_t*)(senders[0].data);
    if (*x >= world->width && *y >= world->height)
        return (-1);
    write_map_tile_content(&world->tiles[*x][*y], *x, *y, senders[0].sockfd);
    free(senders);
    return (0);
}
