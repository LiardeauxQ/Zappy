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

csv_data_t parse_csv(const char *filename);

/* str_to_word_array.c */

char **str_to_word_array(char const *str, char *c);

/* free_array.c */

void free_array(char **array);
