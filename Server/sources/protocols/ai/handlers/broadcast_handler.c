/*
** EPITECH PROJECT, 2018
** player_info_handlers.c
** File description:
** Handle every action on player informations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ai/handlers/player_info_handlers.h"

int broadcast_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    player->hatch_left_time = 600;
    set_response("ok\n");
    return (NO_ERROR);
}
