/*
** EPITECH PROJECT, 2018
** test_operations.c
** File description:
** test operations
*/

#include <criterion/criterion.h>

#include "csv.h"
#include "operations.h"

Test(operations, simple_test)
{
    csv_data_t *data = parse_csv("library/csv/tests/data/data.csv");

    if (data == 0x0)
        cr_assert_fail();
    cr_assert_eq(data->size, 3);
    cr_assert_eq(find_id_for_name(data, "name"), 0);
    cr_assert_eq(find_id_for_name(data, "age"), 1);
    cr_assert_eq(find_id_for_name(data, "town"), 2);
    free_csv_data(data);
}

Test(operations, with_wrong_value)
{
    csv_data_t *data = parse_csv("library/csv/tests/data/data.csv");

    if (data == 0x0)
        cr_assert_fail();
    cr_assert_eq(data->size, 3);
    cr_assert_eq(find_id_for_name(data, "quentin"), -2);
    free_csv_data(data);
}

Test(operations, with_no_parameters)
{
    csv_data_t *data = parse_csv("library/csv/tests/data/data.csv");

    if (data == 0x0)
        cr_assert_fail();
    cr_assert_eq(data->size, 3);
    cr_assert_eq(find_id_for_name(0x0, "quentin"), -1);
    cr_assert_eq(find_id_for_name(0x0, 0x0), -1);
    cr_assert_eq(find_id_for_name(data, 0x0), -1);
    free_csv_data(data);
}
