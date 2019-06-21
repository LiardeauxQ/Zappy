/*
** EPITECH PROJECT, 2018
** movement_handlers.c
** File description:
** Handle every moves made by the player.
*/

#include <time.h>

#include "ai/handlers/movement_handlers.h"

int forward_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    switch (player->orientation) {
        case NORTH:
            player->y -= 1;
            break;
        case EAST:
            player->x += 1;
            break;
        case SOUTH:
            player->y += 1;
            break;
        case WEST:
            player->x -= 1;
            break;
    }
    set_response("ok");
    return (NO_ERROR);
}

int left_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    player->orientation--;
    set_response("ok");
    return (NO_ERROR);
}

int right_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    player->orientation++;
    set_response("ok");
    return (NO_ERROR);
}
