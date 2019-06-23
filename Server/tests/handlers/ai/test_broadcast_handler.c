/*
** EPITECH PROJECT, 2018
** movement_handlers.c
** File description:
** Movement handlers - Unit Tests
*/

#include <criterion/criterion.h>
#include "ai/handlers/movement_handlers.h"

Test(broadcast_handler, test_broadcast_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *player = 0x0;

    add_player(&world, 0);
    cr_assert_eq(strcmp(get_response(), "ok\n"), 0);
}

