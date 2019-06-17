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
    csv_data_t *data = parse_csv("library/csv/tests/data/data.csv");

    if (data == 0x0) {
        data = parse_csv("tests/data/data.csv");
        if (data == 0x0)
            cr_assert_fail();
    }
    cr_assert_eq(data->size, 3);
    cr_assert_str_eq(data->columns[0].name, "name");
    cr_assert_str_eq(data->columns[1].name, "age");
    cr_assert_str_eq(data->columns[2].name, "town");
    cr_assert_str_eq(data->columns[0].values[0], "quentin");
    free_csv_data(data);
}

Test(parse_csv, simple_end_value_test)
{
    csv_data_t *data = parse_csv("library/csv/tests/data/data.csv");

    if (data == 0x0) {
        data = parse_csv("tests/data/data.csv");
        if (data == 0x0)
            cr_assert_fail();
    }
    cr_assert_eq(data->size, 3);
    cr_assert_eq(data->columns[3].size, 0);
    cr_assert_eq(data->columns[3].name, 0x0);
    cr_assert_eq(data->columns[3].values, 0x0);
    free_csv_data(data);
}

Test(parse_csv, create_without_file)
{
    csv_data_t *data = malloc(sizeof(csv_data_t));

    create_csv_columns("name;percentage", data);
    add_value_to_column(&data->columns[0], "Food");
    add_value_to_column(&data->columns[0], "Linemate");
    add_value_to_column(&data->columns[0], "Sibur");
    add_value_to_column(&data->columns[1], "26");
    add_value_to_column(&data->columns[1], "5");
    add_value_to_column(&data->columns[1], "50");

    cr_assert_eq(data->size, 2);
    cr_assert_str_eq(data->columns[0].name, "name");
    cr_assert_str_eq(data->columns[0].values[0], "Food");
    cr_assert_str_eq(data->columns[0].values[1], "Linemate");
    cr_assert_str_eq(data->columns[0].values[2], "Sibur");
    cr_assert_eq(data->columns[0].values[3], 0);
    cr_assert_str_eq(data->columns[1].values[0], "26");
    cr_assert_str_eq(data->columns[1].values[1], "5");
    cr_assert_str_eq(data->columns[1].values[2], "50");
    cr_assert_eq(data->columns[1].values[3], 0);
    cr_assert_eq(data->columns[2].name, 0);
    free_csv_data(data);
}

Test(parse_csv, unknown_file)
{
    csv_data_t *data = parse_csv("unknown_file.csv");

    cr_assert_eq(data, 0x0);
}

Test(parse_csv, no_file)
{
    csv_data_t *data = parse_csv(0x0);

    cr_assert_eq(data, 0x0);
}
