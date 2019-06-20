/*
** EPITECH PROJECT, 2018
** handle_map_size.c
** File description:
** handle map_size interaction
*/

#include <string.h>
#include <unistd.h>

#include "graphical/commands.h"
#include "graphical/protocols.h"
#include "world.h"

int send_map_size(const void *data)
{
    char *to_write = 0x0;
    char *tmp = 0x0;
    size_t size = PKT_HDR_LEN + SRV_MAP_SIZE_LEN;
    sender_t *sender = get_senders_from_data(data);
    world_t *world = 0x0;
    pkt_header_t hdr = {SRV_MAP_SIZE, PROTOCOL_VERSION, SRV_MAP_SIZE_LEN, 0};
    srv_map_size_t map = {0};

    if (sender == 0x0 && sender[0].size != sizeof(world_t))
        return (-1);
    world = (world_t*)sender[0].data;
    map.x = world->width;
    map.y = world->height;
    map = (srv_map_size_t){world->width, world->height};
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HANDLER_LEN);
    tmp = to_write + PKT_HDR_LEN;
    tmp = memcpy(tmp, &map, SRV_MAP_SIZE_LEN);
    write(sender->sockfd, to_write, size);
    return (0);
}
