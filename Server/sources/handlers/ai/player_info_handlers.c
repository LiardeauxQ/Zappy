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

int look_handler(player_t *player, const uint16_t limit_cycles,
        const char __attribute__((unused)) **args)
{
    // Unimplemented
    return (0);
}

int connect_nbr_handler(player_t *player, const uint16_t limit_cycles,
        const char __attribute__((unused)) **args)
{
    // Unimplemented
    return (0);
}

int death_handler(player_t *player, const uint16_t limit_cycles,
        const char __attribute__((unused)) **args)
{
    send_message("dead");
    return (NO_ERROR);
}
