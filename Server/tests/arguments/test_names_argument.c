/*
** EPITECH PROJECT, 2018
** test_names_arguments.c
** File description:
** test names arguments
*/

#include <criterion/criterion.h>
#include "arguments.h"

Test(test_names_arguments, no_arguments)
{
    input_t input = {0};
    char *av[] = {0x0};

    cr_assert_eq(handle_names(av, &input), -1);
}

Test(test_names_arguments, null_arguments)
{
    input_t input = {0};
    char **av = 0x0;

    cr_assert_eq(handle_names(av, &input), -1);
}

Test(test_names_arguments, simple_test)
{
    input_t input = {0};
    char *av[] = {"name1", "name2", 0x0};

    cr_assert_eq(handle_names(av, &input), 0);
    cr_assert_str_eq(input.names[0], "name1");
    cr_assert_str_eq(input.names[1], "name2");
    cr_assert_eq(input.names[3], 0x0);
}
