/*
** EPITECH PROJECT, 2018
** handle_resources.c
** File description:
** handle map resources
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/errno.h>

#include "resources.h"
#include "csv.h"
#include "operations.h"

resource_t *parse_resources(const char *filename)
{
    csv_data_t *data = parse_csv(filename);
    resource_t *resources = 0x0;

    if (data == 0x0)
        return (init_default_resources());
    resources = fill_resources(data);
    free_csv_data(data);
    return (resources == 0x0 ? init_default_resources() : resources);
}

static int check_invalid_value(void)
{
    if (errno == EINVAL) {
        errno = 0;
        return (-1);
    }
    return (0);
}

resource_t *fill_resources(const csv_data_t *data)
{
    int name_id = find_id_for_name(data, "name");
    int percentage_id = find_id_for_name(data, "percentage");
    int resource_id = 0;
    int percentage = 0;
    resource_t *resources = 0x0;
    size_t size = 1;

    if (name_id < 0 || percentage_id < 0)
        return (0x0);
    for (size_t i = 0 ; i < data->columns[name_id].size ; i++) {
        resource_id = find_id_for_resource(data->columns[name_id].values[i]);
        percentage = strtol(data->columns[percentage_id].values[i], 0x0, 10);
        if (check_invalid_value())
            continue;
        resources = realloc(resources, (size + 1) * sizeof(resource_t));
        add_resource(&resources[size - 1], resource_id, percentage,
                data->columns[name_id].values[i]);
        resources[size++] = (resource_t){0};
    }
    return (resources);
}

void add_resource(resource_t *resource, ...)
{
    va_list list;

    va_start(list, resource);
    resource->id = va_arg(list, int);
    resource->percentage = va_arg(list, int);
    resource->name = strdup(va_arg(list, char*));
    va_end(list);
}

void free_resources(resource_t *resources)
{
    for (size_t i = 0 ; resources[i].name != 0x0 ; i++)
        free(resources[i].name);
    free(resources);
}
