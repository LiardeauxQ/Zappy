/*
** EPITECH PROJECT, 2018
** test_defaut_resources.c
** File description:
** test default resources functions
*/

#include <criterion/criterion.h>

#include "resources.h"

Test(init_default_resources, simple_test)
{
    resource_t *resources = init_default_resources();

    cr_assert_eq(resources[0].id, 0);
    cr_assert_str_eq(resources[0].name, "food");
    cr_assert_str_eq(resources[6].name, "thystame");
    free(resources);
}

Test(find_if_for_resources, simple_test)
{
    cr_assert_eq(find_id_for_resource("food"), 0);
    cr_assert_eq(find_id_for_resource("linemate"), 1);
    cr_assert_eq(find_id_for_resource("deraumere"), 2);
    cr_assert_eq(find_id_for_resource("phiras"), 5);
    cr_assert_eq(find_id_for_resource("custom"), 10);
}

Test(find_if_for_resources, bad_value_test)
{
    cr_assert_eq(find_id_for_resource("doesn't work"), -1);
}

Test(find_if_for_resources, no_value_test)
{
    cr_assert_eq(find_id_for_resource(0x0), -2);
}
