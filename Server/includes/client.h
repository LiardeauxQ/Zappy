/*
** EPITECH PROJECT, 2018
** client.h
** File description:
** handle client connection
*/

#pragma once

#include <sys/select.h>

#include "graphical/protocols.h"

#define MAX_CLIENT 30

typedef struct info_s info_t;
typedef struct world_s world_t;

typedef struct client_s {
    int sockfd;
} client_t;

/* handle_clients.c */

int read_client(client_t *client, phr_t *reg, world_t *world);
void handle_clients(info_t *info, fd_set *readfds);
