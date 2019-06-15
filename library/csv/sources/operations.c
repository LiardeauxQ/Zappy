/*
** EPITECH PROJECT, 2018
** operations.c
** File description:
** operations on csv data
*/

#include <string.h>

#include "csv.h"
#include "operations.h"

int find_id_for_name(const csv_data_t *data, const char *name)
{
    if (data == 0x0 || name == 0x0)
        return (-1);
    for (size_t i = 0 ; i < data->size ; i++)
        if (!strcmp(data->columns[i].name, name))
            return (i);
    return (-2);
}
