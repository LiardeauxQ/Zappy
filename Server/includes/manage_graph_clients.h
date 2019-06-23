/*
** EPITECH PROJECT, 2018
** manage_graph_clients.c
** File description:
** Manage graph clients header
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "graphical/client.h"

client_t *get_graph_clients(void);
void set_graph_clients(client_t *clients);
