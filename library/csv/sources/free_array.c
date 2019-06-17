/*
** EPITECH PROJECT, 2018
** free_array.c
** File description:
** free arrays
*/

#include <stdlib.h>

#include "csv.h"

void free_array(char **array)
{
    for (int i = 0 ; array[i] != 0x0 ; i++)
        free(array[i]);
    free(array);
}
