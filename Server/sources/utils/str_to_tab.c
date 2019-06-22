/*
** EPITECH PROJECT, 2017
** myftp
** File description:
** str_to_tab
*/

#include <stdlib.h>
#include <string.h>

#include "utils.h"

char **str_to_tab(char const *str, char const *separators)
{
    int i = 0;
    int shift = 0;
    char *token = 0;
    char *rest = strdup(str);
    char *tmp_ptr = rest;
    char **tab = 0;

    for (i = 0; separators[i]; i++)
        shift = (str[0] == separators[i]) ? 1 : 0;
    for (i = shift; strtok_r(rest, separators, &rest); i++);
    free(tmp_ptr);
    tab = malloc(sizeof(char *) * (i + 1));
    tab[0] = (shift) ? strdup("") : 0;
    tab[i] = 0;
    rest = strdup(str);
    tmp_ptr = rest;
    for (i = shift; (token = strtok_r(rest, separators, &rest)); i++)
        tab[i] = strdup(token);
    free(tmp_ptr);
    return (tab);
}
