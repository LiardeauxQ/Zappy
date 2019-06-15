/*
** EPITECH PROJECT, 2018
** client_nbr.c
** File description:
** handle client_nbr program argument
*/

#include "arguments.h"

int handle_client_nbr(char **av, input_t *input)
{
    if (av == 0x0 || *av == 0x0) {
        fprintf(stderr, "Empty client nbr\n");
        return (-1);
    }
    input->client_nbr = handle_int_argument(*av);
    return (0);
}
