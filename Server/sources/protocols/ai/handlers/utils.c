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

pos_t *next_case(world_t *world, pos_t *pos, int orientation, int inc)
{
    int x_inc[4] = {0, 1, 0, -1};
    int y_inc[4] = {-1, 0, 1, 0};

    if (orientation < 1)
        orientation = 4 - orientation;
    else if (orientation > 4)
        orientation = orientation - 4;
    orientation--;
    pos->x += x_inc[orientation] * inc;
    pos->y += y_inc[orientation] * inc;
    if (pos->x >= (int) world->width)
        pos->x -= (int) world->width;
    if (pos->x < 0)
        pos->x += (int) world->width;
    if (pos->y >= (int) world->height)
        pos->y -= (int) world->height;
    if (pos->y < 0)
        pos->y += (int) world->height;
    return (pos);
}

int is_time_limit_reached(const clock_t start, const uint16_t limit_cycles,
        const unsigned int f)
{
    clock_t end = clock();
    clock_t total = (double) (end - start) / CLOCKS_PER_SEC;

    return (total > limit_cycles / f);
}
