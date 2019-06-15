/*
** EPITECH PROJECT, 2018
** name
** File description:
** handle errors
*/

#include "error.h"

void exit_with_error(char const *msg)
{
    perror(msg);
    exit(EXIT_ERROR);
}

int print_exit_msg(char const *msg, int exit_value)
{
    fprintf(stderr, "%s\n", msg);
    return (exit_value);
}

void check_malloc(void *data)
{
    if (data == 0x0)
        exit(84);
}
