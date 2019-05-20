/*
** EPITECH PROJECT, 2018
** arguments.c
** File description:
** handle program arguments
*/

#include "arguments.h"
#include <stdlib.h>

const struct arguments_s arg_opt[] = {
    {"-p", "--port", &handle_port},
    {"-x", "--width", &handle_width},
    {"-y", "--height", &handle_height},
    {"-n", "--names", &handle_names},
    {"-c", "--clients", &handle_client_nbr},
    {"-f", "--freq", &handle_freq},
    {0x0, 0x0, 0x0}
};

void handle_arguments(int const ac, char **av, input_t *input)
{
    for (int i = 0 ; i < ac ; i++) {
        for (int j = 0 ; arg_opt[j].short_name != 0x0 ; j++) {
            if (!strcmp(arg_opt[j].short_name, av[i])
                    || !strcmp(arg_opt[j].long_name, av[i])) {
                arg_opt[j].fct(av + i + 1, input);
            }
        }
    }
}
