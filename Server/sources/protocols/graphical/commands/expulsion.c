/*
** EPITECH PROJECT, 2018
** handle_expulsion.c
** File description:
** handle expulsion
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"


int send_player_expulsion(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_EXPULSION_LEN;
    srv_player_expulsion_t srv = {0};
    pkt_header_t hdr = {SRV_EXPULSION, PROTOCOL_VERSION,
        SRV_PLAYER_EXPULSION_LEN, 0};

    if (count_senders(senders) != 1)
        return (-1);
    srv.player_num = *((int*)(senders[0].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_PLAYER_EXPULSION_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}
