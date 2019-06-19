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
#include "graphical/protocols.h"

struct input_s {
    unsigned int port;
    unsigned int width;
    unsigned int height;
    unsigned int client_nbr;
    unsigned int frequence;
    char **names;
    char *resources_filename;
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
    phr_t handler_register;
};

typedef struct info_s info_t;

/* destroy_struct.c */

void free_array(char **array);
void free_input(input_t *input);

/* init_info.c */

info_t init_info(int ac, char **av);
void destroy_info(info_t *info);
