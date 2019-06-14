/*
** EPITECH PROJECT, 2018
** connection.h
** File description:
** connection header
*/

#pragma once

#include <sys/socket.h>
#include <string.h>

#include "server.h"
#include "client.h"

int init_connection(server_t *server);
int set_fds(fd_set *readfds, client_t const clients[MAX_CLIENT],
    int const sockfd);
void get_new_connection(fd_set *readfds, client_t (*clients)[MAX_CLIENT],
    int const main_socket);
