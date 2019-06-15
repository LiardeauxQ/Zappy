/*
** EPITECH PROJECT, 2017
** str_to_word_array.c
** File description:
** split str to array when there are seperators
*/

#include <string.h>
#include <stdlib.h>

#include "csv.h"

char **str_to_word_array(char const *str, char *c)
{
    char *tmp = strdup(str);
    char *saveptr = 0x0;
    char *token = strtok_r(tmp, c, &saveptr);
    char **array = 0x0;
    int size = 1;

    if (str == 0x0)
        return (0x0);
    while (token != 0x0) {
        array = realloc(array, (size + 1) * sizeof(char *));
        array[size - 1] = strdup(token);
        tmp = 0x0;
        token = strtok_r(tmp, c, &saveptr);
        size = size + 1;
    }
    if (array != 0x0)
        array[size - 1] = 0x0;
    free(tmp);
    return (array);
}
