/*
** EPITECH PROJECT, 2018
** name
** File description:
** check file extension
*/

#include <string.h>

#include "csv.h"

int check_extension(const char *filename, const char *extension)
{
    char *found = strstr(filename, extension);

    if (strlen(found) == strlen(extension))
        return (0);
    return (-1);
}
