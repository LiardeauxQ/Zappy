/*
** EPITECH PROJECT, 2018
** manage_response.c
** File description:
** Manage responses header
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_response();
void set_response(char *value);

int is_graph_request_ok();
void exec_graph_request();
void set_graph_request(const void *data, int (*fct)(const void *));
