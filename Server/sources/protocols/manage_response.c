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

static char *manage_response(int option, char *value)
{
    static char *response = 0x0;

    if (option)
        response = value;
    return (response);
}

char *get_response()
{
    return (manage_response(0, 0x0));
}

void set_response(char *value)
{
    char *new_value = calloc(1, strlen(value) + 1);

    if (get_response())
        free(get_response());
    strcpy(new_value, value);
    manage_response(1, new_value);
}

void manage_graph_request(int option, char *data, int (*fct)(char *))
{
    static char *request = 0x0;
    static int (*handler)(char *) = 0x0;

    if (!option) {
        request = data;
        handler = fct;
    } else {
        handler(request);
    }
}

void exec_graph_request()
{
    manage_graph_request(1, 0x0, 0x0);
}

void set_graph_request(char *data, int (*fct)(char *))
{
    manage_graph_request(0, data, fct);
}
