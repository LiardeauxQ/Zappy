/*
** EPITECH PROJECT, 2018
** movement_handlers.c
** File description:
** Handle every moves made by the player.
*/

#include <time.h>

#include "ai/handlers/movement_handlers.h"

int forward_move_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char __attribute__((unused)) **args)
{
    int time_limit_passed = 0;
    clock_t start_time = clock();

    switch (player->orientation) {
        case UP:
            player->y -= 1;
            break;
        case RIGHT:
            player->x += 1;
            break;
        case DOWN:
            player->y += 1;
            break;
        case LEFT:
            player->x -= 1;
            break;
    }
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, world->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}

int left_move_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char __attribute__((unused)) **args)
{
    int time_limit_passed = 0;
    clock_t start_time = clock();

    player->orientation--;
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, world->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}

int right_move_handler(world_t *world, player_t *player,
        const uint16_t limit_cycles, const char __attribute__((unused)) **args)
{
    int time_limit_passed = 0;
    clock_t start_time = clock();

    player->orientation++;
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, world->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}
