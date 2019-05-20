/*
** EPITECH PROJECT, 2018
** arguments.h
** File description:
** arguments header
*/

#pragma once

#include <string.h>
#include <stdlib.h>

#include "server.h"
#include "error.h"

#define CONFORM_NAME_CHAR "abcdefghijklmnopqrstuvwxyz"\
                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"\
                          "0123456789_"

struct arguments_s {
    char *short_name;
    char *long_name;
    void (*fct)(char **av, server_info_t *info);
};

extern const struct arguments_s arg_opt[];

/* int_argument.c */

int handle_int_argument(char const *arg);

/* port.c */

void handle_port(char **av, server_info_t *info);

/* width.c */

void handle_width(char **av, server_info_t *info);

/* height.c */

void handle_height(char **av, server_info_t *info);

/* freq.c */

void handle_freq(char **av, server_info_t *info);

/* client_nbr.c */

void handle_client_nbr(char **av, server_info_t *info);

/* names.c */

void handle_names(char **av, server_info_t *info);

/* arguments.c */

void handle_arguments(int const ac, char **av, server_info_t *info);
