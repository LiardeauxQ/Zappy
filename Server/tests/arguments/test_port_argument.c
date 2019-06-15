/*
** EPITECH PROJECT, 2018
** test_port_argument.c
** File description:
** test port argument
*/

#include <criterion/criterion.h>
#include "arguments.h"

Test(test_port_argument, no_arguments)
{
    input_t input = {0};
    char *av[] = {0x0};

    cr_assert_eq(handle_port(av, &input), -1);
}

Test(test_port_argument, null_arguments)
{
    input_t input = {0};
    char **av = 0x0;

    cr_assert_eq(handle_port(av, &input), -1);
}

Test(test_port_argument, simple_test)
{
    input_t input = {0};
    char *av[] = {"34", 0x0};

    cr_assert_eq(handle_port(av, &input), 0);
    cr_assert_eq(input.port, 34);
}

Test(test_port_argument, test_with_unuseful_args)
{
    input_t input = {0};
    char *av[] = {"34", "-f", "12", 0x0};

    cr_assert_eq(handle_port(av, &input), 0);
    cr_assert_eq(input.port, 34);
}
