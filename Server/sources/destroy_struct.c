/*
** EPITECH PROJECT, 2018
** destroy_struct.c
** File description:
** destroy structures
*/

#include "server.h"

void destroy_array(char **array)
{
    if (!array)
        return;
    for (int i = 0 ; array[i] != 0x0 ; i++)
        free(array[i]);
    free(array);
}

void destroy_server_info(info_t *info)
{
    destroy_array(info->input.names);
}
