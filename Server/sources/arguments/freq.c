/*
** EPITECH PROJECT, 2018
** freq.c
** File description:
** handle freq program argument
*/

#include "arguments.h"

void handle_freq(char **av, server_info_t *info)
{
    if (av == 0x0 || *av == 0x0)
        return;
    info->frequence = handle_int_argument(*av);
}
