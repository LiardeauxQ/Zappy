/*
** EPITECH PROJECT, 2018
** width.c
** File description:
** handle width program argument
*/

#include "arguments.h"

int handle_width(char **av, input_t *input)
{
    if (av == 0x0 || *av == 0x0) {
        fprintf(stderr, "Empty width argument\n");
        return (-1);
    }
    input->width = handle_int_argument(*av);
    return (0);
}
