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

sender_t *setup_default_senders(game_t *g, const int sockfd)
{
    sender_t *senders = calloc(sizeof(sender_t), MAX_SENDERS);

    senders[0] = (sender_t){worlddup(&g->world), sizeof(world_t), sockfd, 1};
    senders[MAX_SENDERS - 1].is_last = 1;
    return (senders);
}

int dispatch_receive_data(game_t *g, sender_t *default_senders, int sockfd)
{
    pkt_header_t hdr = {0};
    sender_t sender = {0};
    data_handler handler = 0x0;
    int byte = 0;

    byte = read(sockfd, &hdr, PKT_HDR_LEN);
    if (byte != PKT_HDR_LEN)
        return (-1);
    sender.size = hdr.size;
    sender.sockfd = sockfd;
    sender.data = 0x0;
    sender.is_last = 1;
    read(sockfd, (char*)(sender.data), sender.size);
    default_senders[CUSTOM_SENDER_POS] = sender;
    handler = get_data_handler_for_id(&g->handler_register, hdr.id);
    if (handler(convert_senders_to_data(default_senders)) == -1)
        return (-1);
    return (hdr.subid > 0 ? 1 : 0);
}

int read_graph_client(client_t *clt, game_t *g)
{
    sender_t *senders = setup_default_senders(g, clt->sockfd);
    int result = 0;

    do
        result = dispatch_receive_data(g, senders, clt->sockfd);
    while (result == 1);
    destroy_senders(senders);
    return (0);
}
