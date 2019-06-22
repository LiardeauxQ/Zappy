/*
** EPITECH PROJECT, 2018
** fork_handler.c
** File description:
** Handler client fork
*/

#include "ai/handlers/fork_handler.h"

void hatch(world_t *world, player_t *player)
{
}

int fork_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    player->hatch_start_time = clock();
    set_response("ok\n");
    return (NO_ERROR);
}
