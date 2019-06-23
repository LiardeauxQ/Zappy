/*
** EPITECH PROJECT, 2018
** test_resources.c
** File description:
** test resources functions
*/

#include <criterion/criterion.h>
#include "resources.h"
#include "csv.h"

static csv_data_t *init_simple_csv(int error)
{
    csv_data_t *data = malloc(sizeof(csv_data_t));

    create_csv_columns("name;percentage", data);
    add_value_to_column(&data->columns[0], "food");
    add_value_to_column(&data->columns[0], "linemate");
    add_value_to_column(&data->columns[0], "sibur");
    add_value_to_column(&data->columns[1], "26");
    add_value_to_column(&data->columns[1], (error == 1) ? "error" : "5");
    add_value_to_column(&data->columns[1], "50");
    return (data);
}

static csv_data_t *init_wrong_csv(void)
{
    csv_data_t *data = malloc(sizeof(csv_data_t));

    create_csv_columns("name;age", data);
    add_value_to_column(&data->columns[0], "food");
    add_value_to_column(&data->columns[0], "linemate");
    add_value_to_column(&data->columns[0], "sibur");
    add_value_to_column(&data->columns[1], "26");
    add_value_to_column(&data->columns[1], "error");
    add_value_to_column(&data->columns[1], "50");

    return (data);
}

Test(fill_resources, simple_test)
{
    csv_data_t *data = init_simple_csv(0);
    resource_t *resources = fill_resources(data);

    cr_assert_eq(resources[0].id, 0);
    cr_assert_str_eq(resources[0].name, "food");
    cr_assert_eq(resources[0].percentage, 26);
    cr_assert_eq(resources[1].id, 1);
    cr_assert_str_eq(resources[1].name, "linemate");
    cr_assert_eq(resources[1].percentage, 5);
    cr_assert_eq(resources[2].id, 3);
    cr_assert_str_eq(resources[2].name, "sibur");
    cr_assert_eq(resources[2].percentage, 50);
}

Test(fill_resources, test_with_data_error)
{
    csv_data_t *data = init_simple_csv(1);
    resource_t *resources = fill_resources(data);

    cr_assert_eq(resources[0].id, 0);
    cr_assert_str_eq(resources[0].name, "food");
    cr_assert_eq(resources[0].percentage, 26);
    cr_assert_eq(resources[1].id, 3);
    cr_assert_str_eq(resources[1].name, "sibur");
    cr_assert_eq(resources[1].percentage, 50);
}

Test(fill_resources, test_with_bad_names)
{
    csv_data_t *data = init_wrong_csv();
    resource_t *resources = fill_resources(data);

    cr_assert_eq(resources, 0);
}
