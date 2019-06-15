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
    int (*fct)(char **av, input_t *input);
};

extern const struct arguments_s arg_opt[];

/* int_argument.c */

int handle_int_argument(char const *arg);

/* port.c */

int handle_port(char **av, input_t *input);

/* width.c */

int handle_width(char **av, input_t *input);

/* height.c */

int handle_height(char **av, input_t *input);

/* freq.c */

int handle_freq(char **av, input_t *input);

/* client_nbr.c */

int handle_client_nbr(char **av, input_t *input);

/* names.c */

int handle_names(char **av, input_t *input);

/* resources.c */

int handle_resources(char **av, input_t *input);

/* arguments.c */

void handle_arguments(int const ac, char **av, input_t *input);
