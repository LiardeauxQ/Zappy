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

char *get_response();
void set_response(char *value);

void exec_graph_request();
void set_graph_request(void *data, int (*fct)(const void *));
void manage_graph_request(int option, void *data, int (*fct)(const void *));
