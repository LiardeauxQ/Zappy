/*
** EPITECH PROJECT, 2018
** linked_list.h
** File description:
** linked_list header
*/

#pragma once

#include <stdlib.h>

struct node {
    void *data;
    struct node *next;
    struct node *prev;
};

typedef struct node node_t;

struct linked_list {
    node_t *head;
    node_t *tail;
};

typedef struct linked_list linked_list_t;

void append(linked_list_t *list, void *data);
void insert(linked_list_t *list, size_t pos, void *data);
void *pop(linked_list_t *list);
void *delete_elem(linked_list_t *list, size_t pos);
