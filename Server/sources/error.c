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