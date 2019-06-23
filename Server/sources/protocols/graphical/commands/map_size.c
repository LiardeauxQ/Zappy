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

int assign_map_size(world_t *world, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[WORLD_SENDER_POS] = (sender_t){world, sizeof(world_t), sockfd, 0};
    senders[CUSTOM_SENDER_POS].is_last = 1;
    return (send_map_size(convert_senders_to_data(senders)));
}

int send_map_size(const void *data)
{
    char *to_write = 0x0;
    char *tmp = 0x0;
    size_t size = PKT_HDR_LEN + SRV_MAP_SIZE_LEN;
    sender_t *senders = get_senders_from_data(data);
    world_t *world = 0x0;
    pkt_header_t hdr = {SRV_MAP_SIZE, PROTOCOL_VERSION, SRV_MAP_SIZE_LEN, 0};
    srv_map_size_t map = {0};

    if (count_senders(senders) != MAX_SENDERS)
        return (-1);
    world = (world_t*)senders->data;
    map = (srv_map_size_t){world->width, world->height};
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    tmp = to_write + PKT_HDR_LEN;
    tmp = memcpy(tmp, &map, SRV_MAP_SIZE_LEN);
    write(senders->sockfd, to_write, size);
    free(to_write);
    return (SRV_MAP_SIZE);
}
