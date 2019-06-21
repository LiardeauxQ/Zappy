/*
** EPITECH PROJECT, 2018
** client.h
** File description:
** handle client connection
*/

#pragma once

#include <sys/select.h>
#include <sys/socket.h>

#include "graphical/protocols.h"

#define MAX_CLIENT 30

typedef struct game_s game_t;
typedef struct server_s server_t;
typedef struct world_s world_t;

typedef struct client_s {
    int sockfd;
    int client_nb;
    struct sockaddr_in addr;
} client_t;

typedef int (*client_reader)(client_t *, game_t *);

/* handle_clients.c */

void handle_clients(game_t *game, client_t (*clients)[MAX_CLIENT],
        fd_set *readfds, client_reader reader);
