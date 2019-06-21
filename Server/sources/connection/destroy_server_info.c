/*
** EPITECH PROJECT, 2018
** destroy_server_info.c
** File description:
** destroy structures
*/

#include "server.h"

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0 ; array[i] != 0x0 ; i++)
        free(array[i]);
    free(array);
}

void free_input(input_t *input)
{
    if (input->names)
        free_array(input->names);
    if (input->resources_filename)
        free(input->resources_filename);
}
