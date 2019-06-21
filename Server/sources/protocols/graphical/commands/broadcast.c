/*
** EPITECH PROJECT, 2018
** handle_broadcast.c
** File description:
** handle broadcast
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"


int send_broadcast(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_BROADCAST_MSG_LEN;
    srv_broadcast_msg_t srv = {0};
    pkt_header_t hdr = {SRV_BROADCAST, PROTOCOL_VERSION,
        SRV_BROADCAST_MSG_LEN, 0};

    if (count_senders(senders) != 2)
        return (-1);
    if (senders[0].size == LONG_MSG_LEN)
        strcpy(srv.message, (char*)(senders[0].data));
    srv.player_num = *((int*)(senders[1].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_BROADCAST_MSG_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}
