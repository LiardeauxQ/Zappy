/*
** EPITECH PROJECT, 2018
** test_parse_csv.c
** File description:
** test csv parser
*/

#include <criterion/criterion.h>
#include "csv.h"

Test(parse_csv, simple_test)
{
    csv_data_t *data = parse_csv("tests/data/data.csv");

    cr_assert_eq(data->size, 3);
    cr_assert_str_eq(data->columns[0].name, "name");
    cr_assert_str_eq(data->columns[1].name, "age");
    cr_assert_str_eq(data->columns[2].name, "town");
    cr_assert_str_eq(data->columns[0].values[0], "quentin");
    //free_csv_data(data);
}

Test(parse_csv, simple_end_value_test)
{
    csv_data_t *data = parse_csv("tests/data/data.csv");

    cr_assert_eq(data->size, 3);
    cr_assert_eq(data->columns[3].size, 0);
    cr_assert_eq(data->columns[3].name, 0x0);
    cr_assert_eq(data->columns[3].values, 0x0);
    //free_csv_data(data);
}

Test(parse_csv, unknown_file)
{
    csv_data_t *data = parse_csv("unknown_file.csv");

    cr_assert_eq(data, 0x0);
}
