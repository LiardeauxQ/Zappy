/*
** EPITECH PROJECT, 2018
** test_packet_handler.c
** File description:
** test packet_handler functions
*/

#include <criterion/criterion.h>
#include "map.h"

Test(create_map, simple_init_test)
{
    map_t map = create_map(3, 3);

    cr_assert_eq(map.width, 3);
    cr_assert_eq(map.height, 3);
}
