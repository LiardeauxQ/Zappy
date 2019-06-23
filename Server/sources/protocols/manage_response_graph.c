/*
** EPITECH PROJECT, 2018
** manage_response.c
** File description:
** Manage response from AI
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "manage_response.h"

void exec_graph_request(void)
{
    manage_graph_request(1, 0x0, 0x0);
}

void set_graph_request(void *data, int (*fct)(const void *))
{
    manage_graph_request(0, data, fct);
}
