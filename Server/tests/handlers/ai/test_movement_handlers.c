/*
** EPITECH PROJECT, 2018
** movement_handlers.c
** File description:
** Movement handlers - Unit Tests
*/

#include <criterion/criterion.h>
#include "ai/handlers/movement_handlers.h"

Test(forward_move_handler, test_forward_move_handler)
{
    int id_is_in_list = 0;
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *player = 0x0;
    node_t *player_id_node = 0x0;

    add_player(&world, 0);
    player = (player_t *) world.players.head->data;
    player->x = 1;
    player->y = 1;
    player->orientation = EAST;
    append(&world.tiles[1][1].players_id, &player->id);
    forward_move_handler(&world, player, 0x0);
    cr_assert_eq(player->x, 2);
    player_id_node = world.tiles[2][1].players_id.head;
    for (; player_id_node; player_id_node = player_id_node->next) {
        if (*(unsigned int *) player_id_node->data == player->id) {
            id_is_in_list = 1;
            break;
        }
    }
    cr_assert_eq(id_is_in_list, 1);
    cr_assert_eq(strcmp(get_response(), "ok"), 0);
}

Test(left_move_handler, test_left_move_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *player = 0x0;

    add_player(&world, 0);
    player = (player_t *) world.players.head;
    player->orientation = EAST;
    left_move_handler(&world, player, 0x0);
    cr_assert_eq(player->orientation, NORTH);
    cr_assert_eq(strcmp(get_response(), "ok"), 0);
}

Test(right_move_handler, test_right_move_handler)
{
    world_t world = generate_world(4, 4, 0, 0x0);
    player_t *player = 0x0;

    add_player(&world, 0);
    player = (player_t *) world.players.head;
    player->orientation = EAST;
    right_move_handler(&world, player, 0x0);
    cr_assert_eq(player->orientation, SOUTH);
    cr_assert_eq(strcmp(get_response(), "ok"), 0);
}
