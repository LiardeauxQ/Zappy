/*
** EPITECH PROJECT, 2018
** handle_clients.c
** File description:
** catch clients commands
*/

#include "server.h"
#include "graphical/protocols.h"
#include <stdio.h>

int handle_current_client(client_t *client)
{
    pkt_header_t hdr = {0};

    if (read(client->sockfd, &hdr, PKT_HDR_LEN) <= 0)
        return (1);
    printf("%d %d %d %d\n", hdr.id, hdr.version, hdr.size, hdr.subid);
    return (0);
}

void handle_clients(struct client_s (*clients)[MAX_CLIENT], fd_set *readfds)
{
    int fd = 0;

    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = (*clients)[i].sockfd;
        if (!FD_ISSET(fd, readfds))
            continue;
        handle_current_client(&(*clients)[i]);
    }
}
