/*
** EPITECH PROJECT, 2018
** server.h
** File description:
** server header
*/

#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/select.h>

#include "client.h"

struct input_s {
    unsigned int port;
    unsigned int width;
    unsigned int height;
    unsigned int client_nbr;
    unsigned int frequence;
    char **names;
};

typedef struct input_s input_t;

struct server_s {
    unsigned int port;
    int sockfd;
    struct sockaddr_in sockaddr;
};

typedef struct server_s server_t;

struct info_s {
    int port;
    struct input_s input;
    struct server_s server;
    struct client_s clients[MAX_CLIENT];
};

typedef struct info_s info_t;

/* destroy_struct.c */

void destroy_array(char **array);
void destroy_server_info(info_t *info);
