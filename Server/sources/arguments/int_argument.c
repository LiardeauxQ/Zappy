/*
** EPITECH PROJECT, 2018
** int_argument.c
** File description:
** handle integer argument
*/

#include "arguments.h"

int handle_int_argument(char const *arg)
{
    int result = 0;

    result = strtol(arg, 0x0, 10);
    if (result == 0 && errno == EINVAL)
        exit_with_error("strtol");
    return (result);
}
