/*
** EPITECH PROJECT, 2018
** port.c
** File description:
** handle port program argument
*/

#include "arguments.h"

void handle_port(char **av, server_info_t *info)
{
    info->port = 0;
    if (av == 0x0 || *av == 0x0)
        return;
    info->port = handle_int_argument(*av);
}
