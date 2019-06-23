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

void *assign_broadcast(char *msg, int size,
        unsigned int *player_num, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[INT_SENDER_POS] = (sender_t){player_num, sizeof(int), sockfd, 0};
    senders[MSG_SENDER_POS] = (sender_t){msg, size, sockfd, 0};
    senders[CUSTOM_SENDER_POS].is_last = 1;
    return (convert_senders_to_data(senders));
}

int send_broadcast(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_BROADCAST_MSG_LEN;
    srv_broadcast_msg_t srv = {0};
    pkt_header_t hdr = {SRV_BROADCAST, PROTOCOL_VERSION,
        SRV_BROADCAST_MSG_LEN, 0};

    if (senders == 0x0)
        return (-1);
    if (senders[MSG_SENDER_POS].size == LONG_MSG_LEN)
        strcpy(srv.message, (char*)(senders[MSG_SENDER_POS].data));
    srv.player_num = *((int*)(senders[INT_SENDER_POS].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_BROADCAST_MSG_LEN);
    write(senders[MSG_SENDER_POS].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (SRV_BROADCAST);
}
