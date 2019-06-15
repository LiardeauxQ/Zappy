/*
** EPITECH PROJECT, 2018
** name
** File description:
** handle resources file argument
*/

#include <string.h>
#include "arguments.h"

int handle_resources(char **av, input_t *input)
{
    input->resources_filename = strdup(*av);
    return (0);
}
