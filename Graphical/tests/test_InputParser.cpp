/*
** EPITECH PROJECT, 2018
** name
** File description:
** Test input parser
*/

#include <criterion/criterion.h>
#include "InputParser.hpp"

Test(inputParser, short_option_test)
{
    char *av[] = {"./zappy", "-p", "1234", "-h", "127.0.0.1", nullptr};
    IO::InputParser parser(5, av);

    cr_assert_eq(parser.getCmdIntOption("-p"), 1234);
    cr_assert_str_eq(parser.getCmdStringOption("-h").c_str(), "127.0.0.1");
}

Test(inputParser, long_option_test)
{
    char *av[] = {"./zappy", "-port", "1234", "-hostname", "127.0.0.1", nullptr};
    IO::InputParser parser(5, av);

    cr_assert_eq(parser.getCmdIntOption("-p", "-port"), 1234);
    cr_assert_str_eq(parser.getCmdStringOption("-h", "-hostname").c_str(), "127.0.0.1");
}
