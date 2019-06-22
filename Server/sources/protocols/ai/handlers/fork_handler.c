/*
** EPITECH PROJECT, 2018
** fork_handler.c
** File description:
** Handler client fork
*/

#include "ai/handlers/fork_handler.h"

void hatch(world_t *world, player_t *player, int f)
{
    if (!player->hatch_start_time)
        return;
    if (is_time_limit_reached(player->hatch_start_time,
                HATCH_TIME, world->f)) {
        world->max_team_size += 1;
        player->hatch_start_time = 0;
    }
}

int fork_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    player->hatch_start_time = clock();
    set_response("ok");
    return (NO_ERROR);
}
