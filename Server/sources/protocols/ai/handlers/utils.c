/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Utils for the handlers
*/

#include <criterion/criterion.h>
#include <stdint.h>
#include <time.h>

#include "ai/handlers/utils.h"

player_t *get_player(linked_list_t players, int id)
{
    node_t *cursor = players.head;

    if (id < 0)
        return (0x0);
    while (cursor) {
        if (((player_t *) cursor->data)->id == (unsigned int) id) {
            return ((player_t *) cursor->data);
        }
        cursor = cursor->next;
    }
    return (0x0);
}

size_t *next_case(world_t *world, size_t *coords, int orientation, int inc)
{
    int x_inc[4] = {0, 1, 0, -1};
    int y_inc[4] = {-1, 0, 1, 0};
    int new_coords[2] = {coords[0], coords[1]};

    orientation--;
    new_coords[0] += x_inc[orientation] * inc;
    new_coords[1] += y_inc[orientation] * inc;
    if (new_coords[0] >= (int) world->width)
        new_coords[0] -= (int) world->width;
    if (new_coords[0] < 0)
        new_coords[0] += (int) world->width;
    if (new_coords[1] >= (int) world->height)
        new_coords[1] -= (int) world->height;
    if (new_coords[1] < 0)
        new_coords[1] += (int) world->height;
    coords[0] = new_coords[0];
    coords[1] = new_coords[1];
    return (coords);
}

int is_time_limit_reached(const clock_t start, const uint16_t limit_cycles,
        const unsigned int f)
{
    clock_t end = clock();
    clock_t total = (double) (end - start) / CLOCKS_PER_SEC;

    return (total > limit_cycles / f);
}
