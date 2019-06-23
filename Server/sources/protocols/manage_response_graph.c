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

int manage_graph_request(int option, void *data,
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

void exec_graph_request(void)
{
    manage_graph_request(1, 0x0, 0x0);
}

void set_graph_request(void *data, int (*fct)(const void *))
{
    manage_graph_request(0, data, fct);
}
