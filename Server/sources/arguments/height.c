/*
** EPITECH PROJECT, 2018
** height.c
** File description:
** handle height program argument
*/

#include "arguments.h"

void handle_height(char **av, server_info_t *info)
{
    if (av == 0x0 || *av == 0x0)
        return;
    info->height = handle_int_argument(*av);
}
