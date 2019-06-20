/*
** EPITECH PROJECT, 2018
** player_info_handlers.c
** File description:
** Player info handlers - Unit Tests
*/

#include <criterion/criterion.h>
#include "ai/handlers/player_info_handlers.h"

Test(look_handler, test_look_handler)
{
    int id = 0;
    const char *args[] = {"Linemate", NULL};
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *head = 0x0;

    world.f = 100;
    append(&world.tiles[1][1].players_id, &id);
    add_player(&world, 0);
    head = (player_t *) world.players.head->data;
    head->level = 1;
    head->x = 1;
    head->y = 1;
    look_handler(&world, head, 100, args);
}
