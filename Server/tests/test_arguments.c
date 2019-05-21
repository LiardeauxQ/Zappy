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
