/*
** EPITECH PROJECT, 2018
** handle_map_content.c
** File description:
** handle map_content
*/

#include <string.h>
#include <unistd.h>

#include "graphical/commands.h"
#include "graphical/protocols.h"
#include "world.h"

static void write_map_content(world_t *world, const int sockfd)
{
    char *to_write = 0x0;
    char *tmp = 0x0;
    size_t size = PKT_HANDLER_LEN + (world->width * world->height
            * SRV_TILE_CONTENT_LEN) + 1;
    size_t offset = PKT_HANDLER_LEN;
    pkt_header_t hdr = {SRV_MAP_SIZE, PROTOCOL_VERSION, size, 0};
    srv_tile_content_t current_tile = {0};

    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HANDLER_LEN);
    for (size_t i = 0 ; i < world->width ; i++) {
        for (size_t j = 0 ; j < world->height ; j++) {
            current_tile = convert_to_srv_tile_content(&world->tiles[i][j], i, j);
            tmp = to_write + offset;
            tmp = memcpy(tmp, &current_tile, SRV_TILE_CONTENT_LEN);
            offset += SRV_TILE_CONTENT_LEN;
        }
    }
    write(sockfd, to_write, size);
}

int send_map_content(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    size_t size = count_senders(senders);
    world_t *world = 0x0;

    if (size != 1)
        return (-1);
    world = (world_t*)(senders[0].data);
    write_map_content(world, senders[0].sockfd);
    free(senders);
    return (0);
}
