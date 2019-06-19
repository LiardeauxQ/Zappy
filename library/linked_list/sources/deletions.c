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
    size_t current_pos = 0;

    if (tmp == 0x0)
        return (0x0);
    while (tmp->next && current_pos < pos) {
        tmp = tmp->next;
        current_pos++;
    }
    data = tmp->data;
    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    free(tmp);
    return (data);
}

void delete_linked_list(linked_list_t *list)
{
    node_t *tmp = list->head;

    while (tmp) {
        free(tmp);
        tmp = tmp->next;
    }
    list->head = 0x0;
    list->tail = 0x0;
}
