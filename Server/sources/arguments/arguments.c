/*
** EPITECH PROJECT, 2018
** arguments.c
** File description:
** handle program arguments
*/

#include <stdlib.h>

#include "arguments.h"

const struct arguments_s arg_opt[] = {
    {"-p", "--port", &handle_port},
    {"-x", "--width", &handle_width},
    {"-y", "--height", &handle_height},
    {"-n", "--names", &handle_names},
    {"-c", "--clients", &handle_client_nbr},
    {"-f", "--freq", &handle_freq},
    {"-r", "--resources", &handle_resources},
    {0x0, 0x0, 0x0}
};

void handle_arguments(int const ac, char **av, input_t *input)
{
    if (input == 0x0 || av == 0x0)
        return;
    for (int i = 0 ; i < ac && av[i] != 0x0 ; i++) {
        for (int j = 0 ; arg_opt[j].short_name != 0x0 ; j++) {
            if (strcmp(arg_opt[j].short_name, av[i])
                    && strcmp(arg_opt[j].long_name, av[i]))
                continue;
            if (arg_opt[j].fct(av + i + 1, input) == -1)
                return;
        }
    }
}
