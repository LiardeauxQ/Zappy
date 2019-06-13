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

char *resource_to_string(const enum RESOURCE_ID id, const int quantity)
{
    char *ressources_strings[7] = {"food", "linemate", "deraumere", "sibur", \
        "mendiane", "phiras", "thystame"};
    int ressource_string_len = strlen(ressources_strings[id]);
    int len = ressource_string_len + 1 + snprintf(0x0, 0, "%d", quantity) + 1;
    char *str = calloc(1, sizeof(char) * len);

    strcat(str, ressources_strings[id]);
    sprintf(str + ressource_string_len, "%d", quantity);
    str[len - 1] = 0;
    return (str);
}

enum RESOURCE_ID resource_str_to_id(const char *resource)
{
    char *ressources_strings[6] = {"food", "linemate", "deraumere", "sibur", \
        "mendiane", "phiras", "thystame"};
    
    for (int i = 0; i < 6; i++) {
        if (!strcmp(ressources_strings[i], resource))
            return (i);
    }
    return (-1);
}

int take_object_handler(player_t *player, const uint16_t limit_cycles,
        const char **args)
{
    int time_limit_passed = 0;
    enum RESOURCE_ID resource_id = 0;
    clock_t start_time = clock();

    if (!args[0])
        return (TOO_FEW_PARAMETERS);
    else if (args[1])
        return (TOO_MUCH_PARAMETERS);
    resource_id = resource_str_to_id(args[0]);
    if ((int) resource_id == -1)
        return (INVALID_PARAMETERS);
    player->resources[resource_id]++;
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, player->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}

int set_down_object_handler(player_t *player, const uint16_t limit_cycles,
        const char **args)
{
    int time_limit_passed = 0;
    enum RESOURCE_ID resource_id = 0;
    clock_t start_time = clock();

    if (!args[0])
        return (TOO_FEW_PARAMETERS);
    else if (args[1])
        return (TOO_MUCH_PARAMETERS);
    resource_id = resource_str_to_id(args[0]);
    if ((int) resource_id == -1)
        return (INVALID_PARAMETERS);
    player->resources[resource_id]--;
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, player->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}

int inventory_handler(player_t *player, const uint16_t limit_cycles,
        const char __attribute__((unused)) **args)
{
    int time_limit_passed = 0;
    clock_t start_time = clock();
    char *resource_string = 0x0;
    char *inventory = calloc(1, 2);

    for (int i = 0; i < 6; i++) {
        if (i == 0)
            strcat(inventory, "[");
        resource_string = resource_to_string(i, player->resources[i + 1]);
        inventory = realloc(inventory, strlen(inventory) + strlen(resource_string) + 1);
        strcat(inventory , resource_string);
        if (i == sizeof(player->resources) / 4 - 1)
            strcat(inventory , "]");
    }
    printf("%s", inventory);
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, player->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}
