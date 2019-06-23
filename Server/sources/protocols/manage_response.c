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

char *get_response(void)
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

int manage_graph_request(int option, const void *data,
        int (*fct)(const void *))
{
    static void *request = 0x0;
    static int (*handler)(const void *) = 0x0;

    if (!option) {
        request = data;
        handler = fct;
        exec_graph_request();
    } else if (option == 1) {
        handler(request);
        request = 0x0;
        handler = 0x0;
    } else {
        return (request && handler);
    }
    return (1);
}

int is_graph_request_ok()
{
    return manage_graph_request(2, 0x0, 0x0);
}
