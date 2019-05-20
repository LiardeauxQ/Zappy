/*
** EPITECH PROJECT, 2018
** port.c
** File description:
** handle port program argument
*/

#include "arguments.h"

void handle_port(char **av, input_t *input)
{
    if (av == 0x0 || *av == 0x0)
        return;
    input->port = handle_int_argument(*av);
}
