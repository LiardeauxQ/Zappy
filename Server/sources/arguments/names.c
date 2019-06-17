/*
** EPITECH PROJECT, 2018
** names.c
** File description:
** handle names arguments
*/

#include "arguments.h"

int handle_names(char **av, input_t *input)
{
    int i = 0;

    if (av == 0x0)
        return (-1);
    free_array(input->names);
    for (; av[i] != 0x0 ; i++) {
        if (!strchr(CONFORM_NAME_CHAR, av[i][0]))       
            break;
        input->names = realloc(input->names, (i + 2) * sizeof(char *));
        input->names[i] = strdup(av[i]);
    }
    if (!i) {
        input->names = 0x0;
        fprintf(stderr, "No names\n");
        return (-1);
    }
    input->names[i] = 0x0;
    return (0);
}
