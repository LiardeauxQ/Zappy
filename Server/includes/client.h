/*
** EPITECH PROJECT, 2018
** client.h
** File description:
** handle client connection
*/

/**
 * \file client.h
 * \brief client functions.
 * \date Jun, 23 2019
 *
 */

#pragma once

#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>


#include "graphical/protocols.h"

#define MAX_CLIENT 30

typedef struct game_s game_t;
typedef struct server_s server_t;
typedef struct world_s world_t;

enum client_type {
    AI,
    GRAPH
};

typedef struct client_s {
    int sockfd;
    int client_nb;
    enum client_type type;
    struct sockaddr_in addr;
} client_t;

typedef int (*client_reader)(client_t *, game_t *);

/* handle_clients.c */

void handle_clients(game_t *game, client_t (*clients)[MAX_CLIENT],
        fd_set *readfds, client_reader reader);
