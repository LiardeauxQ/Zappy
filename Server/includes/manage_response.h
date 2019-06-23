/*
** EPITECH PROJECT, 2018
** manage_response.c
** File description:
** Manage responses header
*/

/**
 * \file manage_response.h
 * \brief manage response functions.
 * \date Jun, 23 2019
 *
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_response(void);
void set_response(char *value);

int is_graph_request_ok(void);
void exec_graph_request(void);
void set_graph_request(const void *data, int (*fct)(const void *));
int manage_graph_request(int option, const void *data,
        int (*fct)(const void *));

