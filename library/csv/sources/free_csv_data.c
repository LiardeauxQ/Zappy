/*
** EPITECH PROJECT, 2018
** free_csv_data.c
** File description:
** free csv data struct
*/

#include <stdlib.h>

#include "csv.h"

void free_csv_columns(csv_column_t *column)
{
    if (column->name)
        free(column->name);
    if (column->values) {
        for (size_t i = 0 ; i < column->size ; i++)
            free(column->values[i]);
        free(column->values);
    }
    free(column);
}

void free_csv_data(csv_data_t *data)
{
    for (size_t i = 0 ; i < data->size ; i++)
        free_csv_columns(&data->columns[i]);
}
