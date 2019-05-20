/*
** EPITECH PROJECT, 2018
** server.h
** File description:
** server header
*/

#pragma once

#include <stdlib.h>

typedef struct server_info_s {
    unsigned int port;
    unsigned int width;
    unsigned int height;
    unsigned int client_nbr;
    unsigned int frequence;
    char **names;
} server_info_t;

/* destroy_struct.c */

void destroy_array(char **array);
void destroy_server_info(server_info_t *info);
