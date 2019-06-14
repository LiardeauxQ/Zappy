/*
** EPITECH PROJECT, 2018
** test_arguments.c
** File description:
** test arguments handling
*/

#include <criterion/criterion.h>
#include "arguments.h"

Test(test_arguments, no_arguments)
{
    input_t input = {0};
    char *av[] = {"./zappy_server", 0x0};

    handle_arguments(1, av, &input);
    cr_assert_eq(input.port, 0);
    cr_assert_eq(input.width, 0);
    cr_assert_eq(input.height, 0);
    cr_assert_eq(input.client_nbr, 0);
    cr_assert_eq(input.frequence, 0);
    cr_assert_eq(input.names, 0x0);
}

Test(test_arguments, with_arguments_1)
{
    input_t input = {0};
    char *av[] = {"./zappy_server", "-p", "45", "-x", "67", "-y", "67", 0x0};

    handle_arguments(7, av, &input);
    cr_assert_eq(input.port, 45);
    cr_assert_eq(input.width, 67);
    cr_assert_eq(input.height, 67);
    cr_assert_eq(input.client_nbr, 0);
    cr_assert_eq(input.frequence, 0);
    cr_assert_eq(input.names, 0x0);
}

Test(test_arguments, with_arguments_2)
{
    input_t input = {0};
    char *av[] = {"./zappy_server", "-c", "23", "-f", "67", 0x0};

    handle_arguments(5, av, &input);
    cr_assert_eq(input.port, 0);
    cr_assert_eq(input.width, 0);
    cr_assert_eq(input.height, 0);
    cr_assert_eq(input.client_nbr, 23);
    cr_assert_eq(input.frequence, 67);
    cr_assert_eq(input.names, 0x0);
}

Test(test_arguments, with_arguments_names)
{
    input_t input = {0};
    char *av[] = {"./zappy_server", "-n", "name1", "name2", "name3", "-c", "34", 0x0};

    handle_arguments(7, av, &input);
    cr_assert_eq(input.port, 0);
    cr_assert_eq(input.width, 0);
    cr_assert_eq(input.height, 0);
    cr_assert_eq(input.client_nbr, 34);
    cr_assert_eq(input.frequence, 0);
    cr_assert_str_eq(input.names[0], "name1");
    cr_assert_str_eq(input.names[1], "name2");
    cr_assert_str_eq(input.names[2], "name3");
    cr_assert_eq(input.names[3], 0x0);
}
