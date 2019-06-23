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

void *assign_tile_content(world_t *world, clt_tile_content_t *clt, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[WORLD_SENDER_POS] = (sender_t){world, sizeof(world_t),
        sockfd, 0};
    senders[CUSTOM_SENDER_POS] = (sender_t){clt, sizeof(clt_tile_content_t),
        sockfd, 1};
    return (convert_senders_to_data(senders));
}

char *write_tile_content(tile_content_t *tile,
        const unsigned int x, const unsigned int y, const int subid)
{
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_TILE_CONTENT_LEN;
    pkt_header_t hdr = {SRV_TILE_CONTENT, PROTOCOL_VERSION,
        SRV_TILE_CONTENT_LEN, subid};
    srv_tile_content_t srv_content = {0};

    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    srv_content = convert_to_srv_tile_content(tile, x, y);
    memcpy(to_write + PKT_HDR_LEN, &srv_content, SRV_TILE_CONTENT_LEN);
    return (to_write);
}

int send_tile_content(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    size_t size = PKT_HDR_LEN + SRV_TILE_CONTENT_LEN;
    world_t *world = 0x0;
    clt_tile_content_t *clt = {0};
    char *to_write = 0x0;

    if (senders == 0x0)
        return (-1);
    clt = (clt_tile_content_t*)senders[CUSTOM_SENDER_POS].data;
    world = (world_t*)(senders[WORLD_SENDER_POS].data);
    if (clt->x >= world->width && clt->y >= world->height)
        return (-1);
    to_write = write_tile_content(&world->tiles[clt->x][clt->y], clt->x,
            clt->y, 0);
    write(senders[WORLD_SENDER_POS].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (SRV_TILE_CONTENT);
}
