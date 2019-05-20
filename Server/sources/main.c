/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "server.h"
#include "arguments.h"
#include "connection.h"

int main(int ac, char **av)
{
    info_t info = {0};

    handle_arguments(ac, av, &info.input);
    info.server.port = info.input.port;
    init_connection(&info.server);
    return (0);
}
