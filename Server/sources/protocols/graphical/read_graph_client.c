/*
** EPITECH PROJECT, 2018
** read_graph_client.c
** File description:
** read graphical's client protocol
*/

#include <stdio.h>

#include "server.h"
#include "graphical/protocols.h"
#include "graphical/commands.h"
#include "graphical/packets.h"
#include "graphical/client.h"

int read_graph_client(client_t *clt, game_t *g)
{
    size_t i = 1;
    pkt_header_t tmp = {0};
    sender_t *sdrs = calloc(sizeof(sender_t), i);
    data_handler handler = 0x0;

    sdrs[0] = (sender_t){worlddup(&g->world), sizeof(world_t), clt->sockfd, 1};
    do {
        if (read(clt->sockfd, &tmp, PKT_HDR_LEN) != PKT_HDR_LEN
                || tmp.id > SRV_CUSTOM)
            return (-1);
        sdrs = realloc(sdrs, (i + 1) * sizeof(sender_t));
        sdrs[i] = (sender_t){malloc(tmp.size), tmp.size,
            clt->sockfd, 1};
        read(clt->sockfd, (char*)sdrs[i].data, tmp.size);
        sdrs[i - 1].is_last = 0;
        handler = get_data_handler_for_id(&g->handler_register, tmp.id);
        handler(convert_senders_to_data(sdrs));
        i++;
        printf("tmp size %d\n", tmp.size);
    } while (tmp.size > 0);
    destroy_senders(sdrs);
    return (0);
}

