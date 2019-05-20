/*
** EPITECH PROJECT, 2018
** width.c
** File description:
** handle width program argument
*/

#include "arguments.h"

void handle_width(char **av, server_info_t *info)
{
    info->width = 0;
    if (av == 0x0 || *av == 0x0)
        return;
    info->width = handle_int_argument(*av);
}
