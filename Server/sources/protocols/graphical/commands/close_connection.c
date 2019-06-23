/*
** EPITECH PROJECT, 2018
** close_connection.c
** File description:
** handle server message
*/

#include <string.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

int get_close_connection(const void *data)
{
    return (send_close_connection(data));
}

int send_close_connection(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + CLT_CLOSE_CONNECTION_LEN;
    clt_close_connection_t clt = {6};
    pkt_header_t hdr = {CLT_CLOSE_CONNECTION, PROTOCOL_VERSION,
        CLT_CLOSE_CONNECTION_LEN, 0};

    if (senders == 0x0)
        return (-1);
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &clt, CLT_CLOSE_CONNECTION_LEN);
    write(senders->sockfd, to_write, size);
    free(to_write);
    return (CLT_CLOSE_CONNECTION);
}
