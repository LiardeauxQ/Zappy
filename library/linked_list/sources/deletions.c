/*
** EPITECH PROJECT, 2018
** deletions.c
** File description:
** delete functions
*/

#include "linked_list.h"

void *pop(linked_list_t *list)
{
    node_t *tmp = (list->tail == 0x0) ? (list->head) : (list->tail);
    void *data = 0x0;

    if (tmp == 0x0)
        return (0x0);
    list->tail = tmp->prev;
    data = tmp->data;
    tmp->prev->next = 0x0;
    free(tmp);
    return (data);
}

void *delete_elem(linked_list_t *list, size_t pos)
{
    node_t *tmp = list->head;
    void *data = 0x0;

    if (tmp == 0x0)
        return (0x0);
    if (!pos)
        list->head = tmp->next;
    for (int i = 0; tmp->next && i < pos; i++)
        tmp = tmp->next;
    data = tmp->data;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    free(tmp);
    return (data);
}

void delete_linked_list(linked_list_t *list)
{
    node_t *tmp = list->head;
    node_t *stock = 0x0;

    while (tmp) {
        stock = tmp->next;
        free(tmp);
        tmp = stock;
    }
    list->head = 0x0;
    list->tail = 0x0;
}
