/*
** EPITECH PROJECT, 2018
** csv.h
** File description:
** parse_csv header
*/

#pragma once

#include <stdlib.h>

struct csv_column_s {
    size_t size;
    char *name;
    char **values;
};

typedef struct csv_column_s csv_column_t;

struct csv_data_s {
    size_t size;
    csv_column_t *columns;
};

typedef struct csv_data_s csv_data_t;

/* parse_csv.c */

csv_data_t *parse_csv(const char *filename);
csv_data_t *create_csv_columns(char *line, csv_data_t *data);
void add_value_to_column(csv_column_t *column, char *value);

/* free_csv_data.c */

void free_csv_columns(csv_column_t *column);
void free_csv_data(csv_data_t *data);

/* check_extension.c */

int check_extension(const char *filename, const char *extension);

/* str_to_word_array.c */

char **str_to_word_array(char const *str, char *c);

/* free_array.c */

void free_array(char **array);
