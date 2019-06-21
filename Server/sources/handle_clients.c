/*
** EPITECH PROJECT, 2018
** handle_clients.c
** File description:
** handle clients interaction
*/

#include <stdio.h>

#include "server.h"
#include "graphical/protocols.h"
#include "graphical/commands.h"
#include "graphical/packets.h"

void handle_clients(game_t *game, client_t (*clients)[MAX_CLIENT],
        fd_set *readfds, client_reader reader)
{
    int fd = 0;
    int result = 0;

    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = (*clients)[i].sockfd;
        if (!FD_ISSET(fd, readfds))
            continue;
        result = reader(&(*clients)[i], game);
        if (result == CLT_CLOSE_CONNECTION)
            FD_CLR(fd, readfds);
    }
}
