/*
** EPITECH PROJECT, 2018
** teams.h
** File description:
** teams header
*/

#pragma once

#include "linked_list.h"

struct team_s {
    int client_nb;
    int id;
    char *name;
    linked_list_t players_id;
};

typedef struct team_s team_t;
