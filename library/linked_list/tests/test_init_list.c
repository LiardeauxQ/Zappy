/*
** EPITECH PROJECT, 2018
** test_init_list.c
** File description:
** test init_list functions
*/

#include <criterion/criterion.h>

#include "linked_list.h"

Test(append, simple_test)
{
    char str[] = "test";
    linked_list_t list = {0};

    append(&list, str);
    cr_assert_eq((char*)list.head->data, str);
}

Test(append, multiple_nodes_test)
{
    char *str[] = {"test0", "test1", "test3", "test4", 0x0};
    linked_list_t list = {0};
    node_t *tmp = 0x0;
    size_t j = 0;

    for (int i = 0 ; str[i] ; i++)
        append(&list, str[i]);
    tmp = list.head;
    while (str[j] && tmp) {
        cr_assert_eq((char*)tmp->data, str[j]);
        tmp = tmp->next;
        j++;
    }
    cr_assert_eq(j, 4);
}

Test(insert, middle_pos_test)
{
    char *str[] = {"test0", "test1", "test3", "test4", 0x0};
    char new[] = "new";
    linked_list_t list = {0};
    node_t *tmp = 0x0;
    int pos = 2;
    int current_pos = 0;

    for (int i = 0 ; str[i] ; i++)
        append(&list, str[i]);
    insert(&list, pos, new);
    tmp = list.head;
    while (tmp->next && current_pos < pos) {
        tmp = tmp->next;
        current_pos++;
    }
    cr_assert_eq((char*)tmp->data, new);
}

Test(insert, start_pos_test)
{
    char *str[] = {"test0", "test1", "test3", "test4", 0x0};
    char new[] = "new";
    linked_list_t list = {0};
    node_t *tmp = 0x0;
    int pos = 0;
    int current_pos = 0;

    for (int i = 0 ; str[i] ; i++)
        append(&list, str[i]);
    insert(&list, pos, new);
    tmp = list.head;
    while (tmp->next && current_pos < pos) {
        tmp = tmp->next;
        current_pos++;
    }
    cr_assert_eq((char*)tmp->data, new);
}
