/*
** EPITECH PROJECT, 2018
** freq.c
** File description:
** handle freq program argument
*/

#include "arguments.h"

int handle_freq(char **av, input_t *input)
{
    if (av == 0x0 || *av == 0x0) {
        fprintf(stderr, "Empty freq argument\n");
        return (-1);
    }
    input->frequence = handle_int_argument(*av);
    return (0);
}
