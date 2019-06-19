/*
** EPITECH PROJECT, 2018
** height.c
** File description:
** handle height program argument
*/

#include "arguments.h"

int handle_height(char **av, input_t *input)
{
    if (av == 0x0 || *av == 0x0) {
        fprintf(stderr, "Empty height argument\n");
        return (-1);
    }
    input->height = handle_int_argument(*av);
    return (0);
}
