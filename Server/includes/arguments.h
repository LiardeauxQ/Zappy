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
    void (*fct)(char **av, input_t *input);
};

extern const struct arguments_s arg_opt[];

/* int_argument.c */

int handle_int_argument(char const *arg);

/* port.c */

void handle_port(char **av, input_t *input);

/* width.c */

void handle_width(char **av, input_t *input);

/* height.c */

void handle_height(char **av, input_t *input);

/* freq.c */

void handle_freq(char **av, input_t *input);

/* client_nbr.c */

void handle_client_nbr(char **av, input_t *input);

/* names.c */

void handle_names(char **av, input_t *input);

/* arguments.c */

void handle_arguments(int const ac, char **av, input_t *input);
