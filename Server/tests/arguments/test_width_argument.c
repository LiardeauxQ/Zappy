/*
** EPITECH PROJECT, 2018
** test_width_argument.c
** File description:
** test width argument
*/

#include <criterion/criterion.h>
#include "arguments.h"

Test(test_width_argument, no_arguments)
{
    input_t input = {0};
    char *av[] = {0x0};

    cr_assert_eq(handle_width(av, &input), -1);
}

Test(test_width_argument, null_arguments)
{
    input_t input = {0};
    char **av = 0x0;

    cr_assert_eq(handle_width(av, &input), -1);
}

Test(test_width_argument, simple_test)
{
    input_t input = {0};
    char *av[] = {"34", 0x0};

    cr_assert_eq(handle_width(av, &input), 0);
    cr_assert_eq(input.width, 34);
}

Test(test_width_argument, test_with_unuseful_args)
{
    input_t input = {0};
    char *av[] = {"34", "-f", "12", 0x0};

    cr_assert_eq(handle_width(av, &input), 0);
    cr_assert_eq(input.width, 34);
}
