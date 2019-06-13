/*
** EPITECH PROJECT, 2018
** movement_handlers.c
** File description:
** Handle every moves made by the player.
*/

#include <time.h>

#include "ai/handlers/movement_handlers.h"

int forward_move_handler(player_t *player, const uint16_t limit_cycles,
        const char __attribute__((unused)) **args)
{
    int time_limit_passed = 0;
    clock_t start_time = clock();

    switch (player->direction) {
        case UP:
            player->position.y -= 1;
            break;
        case RIGHT:
            player->position.x += 1;
            break;
        case DOWN:
            player->position.y += 1;
            break;
        case LEFT:
            player->position.x -= 1;
            break;
    }
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, player->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}

int left_move_handler(player_t *player, const uint16_t limit_cycles,
        const char __attribute__((unused)) **args)
{
    int time_limit_passed = 0;
    clock_t start_time = clock();

    player->direction--;
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, player->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}

int right_move_handler(player_t *player, const uint16_t limit_cycles,
        const char __attribute__((unused)) **args)
{
    int time_limit_passed = 0;
    clock_t start_time = clock();

    player->direction++;
    time_limit_passed = is_time_limit_passed(start_time, limit_cycles, player->f);
    send_message((!time_limit_passed) ? "ok" : "ko");
    return ((!time_limit_passed) ? NO_ERROR : TIME_LIMIT_PASSED);
}
