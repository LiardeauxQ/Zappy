/*
** EPITECH PROJECT, 2018
** resources_handlers.c
** File description:
** Resources handlers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ai/handlers/player_info_handlers.h"

char *resource_to_string(const enum RESOURCE_NUMBER id, const int quantity, resource_t *resources)
{
    int ressource_string_len = strlen(resources[id].name);
    unsigned int len = 0;
    char *str = 0x0;

    if (quantity != -1)
        len = ressource_string_len + 1 + snprintf(0x0, 0, "%d", quantity) + 1;
    else
        len = ressource_string_len + 1;
    str = calloc(1, sizeof(char) * len);
    strcat(str, resources[id].name);
    if (quantity != -1) {
        strcat(str, " ");
        sprintf(str + ressource_string_len + 1, "%d", quantity);
    }
    str[len - 1] = 0;
    return (str);
}

enum RESOURCE_NUMBER resource_str_to_id(const char *resource, resource_t *resources)
{
    for (int i = 0; i < DEFAULT_RESOURCES_NUMBER; i++) {
        if (!strcmp(resources[i].name, resource))
            return (i);
    }
    return (-1);
}

int take_object_handler(world_t *world, player_t *player, const char **args)
{
    enum RESOURCE_NUMBER resource_id = 0;

    if (!args[0])
        return (TOO_FEW_PARAMETERS);
    else if (args[1])
        return (TOO_MUCH_PARAMETERS);
    resource_id = resource_str_to_id(args[0], world->resources);
    if ((int) resource_id == -1)
        return (INVALID_PARAMETERS);
    player->resources[resource_id]++;
    world->tiles[player->x][player->y].resources[resource_id]--;
    set_response("ok");
    return (NO_ERROR);
}

int set_down_object_handler(world_t *world, player_t *player, const char **args)
{
    enum RESOURCE_NUMBER resource_id = 0;

    if (!args[0])
        return (TOO_FEW_PARAMETERS);
    else if (args[1])
        return (TOO_MUCH_PARAMETERS);
    resource_id = resource_str_to_id(args[0], world->resources);
    if ((int) resource_id == -1)
        return (INVALID_PARAMETERS);
    player->resources[resource_id]--;
    world->tiles[player->x][player->y].resources[resource_id]++;
    set_response("ok");
    return (NO_ERROR);
}

int inventory_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    char *resource_string = 0x0;
    char *inventory = calloc(1, 2);

    strcat(inventory, "[");
    for (int i = 1; i < DEFAULT_RESOURCES_NUMBER; i++) {
        resource_string = resource_to_string(i,
                player->resources[i], world->resources);
        inventory = realloc(inventory, strlen(inventory) + strlen(resource_string) + 3);
        strcat(inventory , resource_string);
        if (i == sizeof(player->resources) / 4 - 1)
            strcat(inventory , "]");
        else
            strcat(inventory , ", ");
    }
    set_response(inventory);
    return (NO_ERROR);
}
