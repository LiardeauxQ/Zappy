/*
** EPITECH PROJECT, 2018
** test_init_list2.c
** File description:
** test init_list part2
*/

#include <criterion/criterion.h>

#include "linked_list.h"

Test(pop, simple_test)
{
    char *str[] = {"test0", "test1", "test3", "test4", 0x0};
    linked_list_t list = {0};
    void *data = 0x0;

    for (int i = 0 ; str[i] ; i++)
        append(&list, str[i]);
    data = pop(&list);
    cr_assert_str_eq((char*)data, "test4");
}

Test(delete_elem, simple_test)
{
    char *str[] = {"test0", "test1", "test3", "test4", 0x0};
    linked_list_t list = {0};
    void *data = 0x0;

    for (int i = 0 ; str[i] ; i++)
        append(&list, str[i]);
    data = delete_elem(&list, 1);
    cr_assert_str_eq((char*)data, "test1");
}
