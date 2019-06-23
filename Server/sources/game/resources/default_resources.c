/*
** EPITECH PROJECT, 2018
** default_resources.c
** File description:
** handle default resources
*/

#include <string.h>
#include <stdlib.h>

#include "resources.h"

static const struct resource_s default_resources[] = {
    {0, 50, "food"},
    {1, 25, "linemate"},
    {2, 25, "deraumere"},
    {3, 10, "sibur"},
    {4, 10, "mendiane"},
    {5, 10, "phiras"},
    {6, 10, "thystame"},
    {10, 0, "custom"},
    {0, 0, 0x0},
};

resource_t *init_default_resources(void)
{
    resource_t *resources = malloc((DEFAULT_RESOURCES_NUMBER + 1)
        * sizeof(resource_t));
    size_t i = 0;

    for (; i < DEFAULT_RESOURCES_NUMBER ; i++) {
        resources[i].id = default_resources[i].id;
        resources[i].name = strdup(default_resources[i].name);
        resources[i].percentage = default_resources[i].percentage;
    }
    resources[i] = (resource_t){0};
    return (resources);
}

int find_id_for_resource(char *name)
{
    if (!name)
        return (-2);
    for (int i = 0 ; i < DEFAULT_RESOURCES_NUMBER ; i++)
        if (!strcmp(name, default_resources[i].name))
            return (default_resources[i].id);
    return (-1);
}
