/*
** EPITECH PROJECT, 2018
** server.h
** File description:
** server header
*/

#pragma once

#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

typedef struct input_s {
    unsigned int port;
    unsigned int width;
    unsigned int height;
    unsigned int client_nbr;
    unsigned int frequence;
    char **names;
} input_t;

typedef struct server_s {
    unsigned int port;
    int sockfd;
    struct sockaddr_in sockaddr;
} server_t;

typedef struct info_s {
    unsigned int port;
    struct input_s input;
    struct server_s server;
} info_t;

/* destroy_struct.c */

void destroy_array(char **array);
void destroy_server_info(info_t *info);
