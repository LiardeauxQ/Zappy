/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "server.h"
#include "arguments.h"

int main(int ac, char **av)
{
    server_info_t info = {0};

    handle_arguments(ac, av, &info);
    printf("%d %d %d %d %d\n", info.port, info.frequence, info.width, info.height, info.client_nbr);
    if (info.names == 0x0)
        return (0);
    for (int i = 0 ; info.names[i] != 0x0 ; i++)
        printf("%s\n", info.names[i]);
    return (0);
}
