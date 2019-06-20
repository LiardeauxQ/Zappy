/*
** EPITECH PROJECT, 2018
** resources.h
** File description:
** resources header
*/

#pragma once

#include "csv.h"
#include "graphical/protocols.h"

#define MINIMAL_RESOURCES 7
#define DEFAULT_RESOURCES_NUMBER 8

struct resource_s {
    enum RESOURCE_NUMBER id;
    unsigned char percentage;
    char *name;
};

typedef struct resource_s resource_t;

resource_t *parse_resources(const char *filename);
resource_t *fill_resources(const csv_data_t *data);
void add_resource(resource_t *resource, ...);
void free_resources(resource_t *resources);

/* default_resources.c */

resource_t *init_default_resources(void);

int find_id_for_resource(char *name);
