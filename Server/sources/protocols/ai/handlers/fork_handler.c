/*
** EPITECH PROJECT, 2018
** fork_handler.c
** File description:
** Handler client fork
*/

#include "ai/handlers/fork_handler.h"

int hatch(world_t *world)
{
    world->max_team_size += 1;
}

int fork_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    player->hatch_left_time = 600;
    set_response("ok");
    return (NO_ERROR);
}
