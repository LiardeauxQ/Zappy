/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "server.h"
#include "arguments.h"

int main(int ac, char **av)
{
    info_t info = {0};

    handle_arguments(ac, av, &info.input);
    return (0);
}
