/*
** EPITECH PROJECT, 2018
** port.c
** File description:
** handle port program argument
*/

#include "arguments.h"

int handle_port(char **av, input_t *input)
{
    if (av == 0x0 || *av == 0x0) {
        fprintf(stderr, "Empty port argument\n");
        return (-1);
    }
    input->port = handle_int_argument(*av);
    return (0);
}
