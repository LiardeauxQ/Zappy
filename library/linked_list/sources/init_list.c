/*
** EPITECH PROJECT, 2018
** init_list.c
** File description:
** init linked list
*/

#include "linked_list.h"

void append(linked_list_t *list, void *data)
{
    node_t *new = calloc(sizeof(node_t), 1);

    new->data = data;
    if (list->head == 0x0) {
        list->head = new;
        return;
    }
    if (list->tail == 0x0) {
        new->prev = list->head;
        list->tail = new;
        list->head->next = list->tail;
        return;
    }
    new->prev = list->tail;
    list->tail->next = new;
    list->tail = new;
}

void insert(linked_list_t *list, size_t pos, void *data)
{
    node_t *new = calloc(sizeof(node_t), 1);
    node_t *tmp = list->head;
    size_t current_pos = 0;

    new->data = data;
    while (tmp->next && current_pos < pos) {
        tmp = tmp->next;
        current_pos++;
    }
    if (pos != 0) {
        tmp->prev->next = new;
        new->prev = tmp->prev;
    } else
        list->head = new;
    new->next = tmp;
    tmp->prev = new;
}
