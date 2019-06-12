/*
** EPITECH PROJECT, 2018
** name
** File description:
** main
*/

#include "csv.h"
#include <stdio.h>

int main(int ac, char **av)
{
    csv_data_t data = parse_csv(av[1]);

    printf("size: %d\n", data.size);
    for (int i = 0 ; i < data.size ; i++) {
        printf("name: %s\n", data.columns[i].name);
        for (int j = 0 ; j < data.columns[i].size ; j++) {
            printf("\t%s\n", data.columns[i].values[j]);
        }
    }
    return (0);
}
