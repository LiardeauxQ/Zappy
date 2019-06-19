/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Utils for the handlers
*/

#include <stdint.h>
#include <time.h>

#include "ai/handlers/utils.h"

player_t *get_player(linked_list_t players, int id)
{
    node_t *cursor = players.head;

    while (cursor) {
        if (((player_t *) cursor->data)->id == id) {
            return ((player_t *) cursor->data);
        }
        cursor = cursor->next;
    }
    return (0x0);
}

int *next_case(world_t *world, int *coords, int orientation, int inc)
{
    unsigned int x_inc[4] = {0, 1, 0, -1};
    unsigned int y_inc[4] = {-1, 0, 1, 0};
    unsigned int *next_case = calloc(1, sizeof(unsigned int) * 2);

    coords[0] = coords[0] + x_inc[orientation] * inc;
    coords[1] = coords[1] + y_inc[orientation] * inc;
    if (coords[0] >= world->width)
        coords[0] -= world->width;
    if (coords[1] >= world->height)
        coords[1] -= world->height;
    return (coords);
}

int is_time_limit_passed(const clock_t start, const uint16_t limit_cycles,
        const unsigned int f)
{
    clock_t end = clock();
    clock_t total = (double) (end - start) / CLOCKS_PER_SEC;

    return (total > limit_cycles / f);
}
