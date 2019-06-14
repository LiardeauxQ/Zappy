/*
** EPITECH PROJECT, 2018
** height.c
** File description:
** handle height program argument
*/

#include "arguments.h"

void handle_height(char **av, input_t *input)
{
    if (av == 0x0 || *av == 0x0)
        return;
    input->height = handle_int_argument(*av);
}
