/*
** EPITECH PROJECT, 2018
** parse_csv.c
** File description:
** parse csv file
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "csv.h"

static size_t arrlen(char **array)
{
    size_t size = 0;

    for (; array[size] != 0 ; size++);
    return (size);
}

csv_data_t *create_csv_columns(char *line, csv_data_t *data)
{
    char **splited_line = str_to_word_array(line, ";");
    size_t size = arrlen(splited_line);
    size_t i = 0;

    if (data == 0x0)
        return (0x0);
    data->size = size;
    data->columns = malloc((size + 1) * sizeof(csv_column_t));
    while (splited_line[i] != 0x0) {
        data->columns[i] = (csv_column_t){0};
        data->columns[i].name = strdup(splited_line[i]);
        i++;
    }
    data->columns[i] = (csv_column_t){0};
    free_array(splited_line);
    return (data);
}

void add_value_to_column(csv_column_t *column, char *value)
{
    column->size++;
    column->values = realloc(column->values, (column->size + 1) * sizeof(char*));
    column->values[column->size - 1] = strdup(value);
    column->values[column->size] = 0x0;
}

csv_data_t *read_csv_file(FILE *fp)
{
    size_t linecap = 0;
    ssize_t linelen = 0;
    char *line = 0x0;
    char **splited_line = 0x0;
    csv_data_t *data = calloc(1, sizeof(csv_data_t));
    size_t pos = 0;

    while ((linelen = getline(&line, &linecap, fp)) > 0) {
        line[strlen(line) - 1] = 0;
        if (pos++ == 0) {
            data = create_csv_columns(line, data);
            continue;
        }
        splited_line = str_to_word_array(line, ";");
        for (int i = 0 ; splited_line[i] != 0x0 ; i++)
            add_value_to_column(&data->columns[i], splited_line[i]);
        free_array(splited_line);
        pos++;
    }
    return (data);
}

csv_data_t *parse_csv(const char *filename)
{
    FILE *fp = 0x0;
    csv_data_t *data = 0x0;

    if (filename == 0x0)
        return (0x0);
    if (check_extension(filename, ".csv"))
        return (0x0);
    if ((fp = fopen(filename, "r")) == 0x0)
        return (0x0);
    data = read_csv_file(fp);
    fclose(fp);
    return (data);
}
