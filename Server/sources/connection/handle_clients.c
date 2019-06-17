/*
** EPITECH PROJECT, 2018
** handle_clients.c
** File description:
** catch clients commands
*/

#include "server.h"
#include "graphical/protocols.h"
#include <stdio.h>

int handle_ai_commands(char *command)
{
}

int handle_graph_client_packets(pkt_header_t *hdr)
{
    printf("%d %d %d %d\n", hdr.id, hdr.version, hdr.size, hdr.subid);
}

int handle_current_client(client_t *client)
{
    char *buffer = 0x0;
    size_t line_len = 0;
    FILE *cfp = fdopen(client->sockfd, "r");

    if (getline(&buffer, &line_len, cfp) <= 0 || !buffer || !buffer[0])
        return (-1);
    if (handle_ai_commands(buffer) == -1) {
        handle_graph_client_packets((pkt_header_t *) buffer);
    }
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
