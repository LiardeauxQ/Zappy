/*
** EPITECH PROJECT, 2018
** client.h
** File description:
** handle client connection
*/

#pragma once

#define MAX_CLIENT 30

typedef struct client_s {
    int sockfd;
} client_t;

/* handle_clients.c */

int handle_current_client(client_t *client);
void handle_clients(struct client_s (*clients)[MAX_CLIENT], fd_set *readfds);
