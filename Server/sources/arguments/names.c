/*
** EPITECH PROJECT, 2018
** names.c
** File description:
** handle names arguments
*/

#include "arguments.h"

void handle_names(char **av, server_info_t *info)
{
    int i = 0;

    if (av == 0x0)
        return;
    destroy_array(info->names);
    for (; av[i] != 0x0 ; i++) {
        if (!strchr(CONFORM_NAME_CHAR, av[i][0]))       
            break;
        info->names = realloc(info->names, (i + 2) * sizeof(char *));
        info->names[i] = strdup(av[i]);
    }
    if (!i) {
        info->names = 0x0;
        return;
    }
    info->names[i] = 0x0;
}
