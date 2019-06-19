/*
** EPITECH PROJECT, 2018
** handle_clients.c
** File description:
** catch clients commands
*/

#include <stdio.h>

#include "server.h"
#include "graphical/protocols.h"
#include "graphical/commands.h"
#include "graphical/packets.h"

int read_client(client_t *client, phr_t *reg, world_t *world)
{
    size_t i = 1;
    pkt_header_t tmp = {0};
    sender_t *sdrs = calloc(sizeof(sender_t), i);
    data_handler handler = 0x0;

    sdrs[0] = (sender_t){worlddup(world), sizeof(*world), client->sockfd, 1};
    do {
        if (read(client->sockfd, &tmp, PKT_HDR_LEN) != PKT_HDR_LEN
                || tmp.id > SRV_CUSTOM)
            return (-1);
        sdrs = realloc(sdrs, (i + 1) * sizeof(sender_t));
        sdrs[i] = (sender_t){malloc(tmp.size), tmp.size,
            client->sockfd, 1};
        read(client->sockfd, (char*)sdrs[i].data, tmp.size);
        sdrs[i - 1].is_last = 0;
        handler = get_data_handler_for_id(reg, tmp.id);
        handler(convert_senders_to_data(sdrs));
        i++;
    } while (tmp.size > 0);
    destroy_senders(sdrs);
    return (0);
}

void handle_clients(info_t *info, fd_set *readfds)
{
    int fd = 0;

    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = info->clients[i].sockfd;
        if (!FD_ISSET(fd, readfds))
            continue;
        read_client(&info->clients[i], &info->handler_register, &info->world);
    }
}
