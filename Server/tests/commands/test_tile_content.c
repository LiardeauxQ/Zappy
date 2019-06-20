/*
** EPITECH PROJECT, 2018
** test_tile_content.c
** File description:
** test tile content
*/

#include <criterion/criterion.h>

#include "world.h"
#include "linked_list.h"

Test(send_tile_content, simple_test)
{
}

Test(get_tile_content, simple_test)
{
}

Test(convert_to_srv_tile_content, simple_test)
{
    int ressources[8] = {1, 2, 3, 4, 5, 6, 7, -1};
    linked_list_t list = {0};
    tile_content_t tile = {ressources, list, 0}; 
}
