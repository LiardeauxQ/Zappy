/*
** EPITECH PROJECT, 2018
** test_client_nbr_argument.c
** File description:
** test client_nbr argument
*/

#include <criterion/criterion.h>
#include "arguments.h"

Test(test_client_nbr_argument, no_arguments)
{
    input_t input = {0};
    char *av[] = {0x0};

    cr_assert_eq(handle_client_nbr(av, &input), -1);
}

Test(test_client_nbr_argument, null_arguments)
{
    input_t input = {0};
    char **av = 0x0;

    cr_assert_eq(handle_client_nbr(av, &input), -1);
}

Test(test_client_nbr_argument, simple_test)
{
    input_t input = {0};
    char *av[] = {"34", 0x0};

    cr_assert_eq(handle_client_nbr(av, &input), 0);
    cr_assert_eq(input.client_nbr, 34);
}

Test(test_client_nbr_argument, test_with_unuseful_args)
{
    input_t input = {0};
    char *av[] = {"34", "-f", "12", 0x0};

    cr_assert_eq(handle_client_nbr(av, &input), 0);
    cr_assert_eq(input.client_nbr, 34);
}
