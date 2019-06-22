/*
** EPITECH PROJECT, 2018
** movement_handlers.c
** File description:
** Handle every moves made by the player.
*/

#include "ai/handlers/movement_handlers.h"

void move_player(world_t *world, player_t *player, int x, int y)
{
    int is_found = 0;
    tile_content_t *tile = &world->tiles[player->x][player->y];
    tile_content_t *dest_tile = &world->tiles[x][y];
    node_t *player_node = tile->players_id.head;

    for (int i = 0; player_node; player_node = player_node->next, i++) {
        if (*(unsigned int *) player_node->data == player->id) {
            delete_elem(&tile->players_id, i);
            is_found = 1;
            break;
        }
    }
    if (is_found) {
        append(&dest_tile->players_id, &player->id);
        player->x = x;
        player->y = y;
    }
}

int forward_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    switch (player->orientation) {
        case NORTH:
            move_player(world, player, player->x, player->y - 1);
            break;
        case EAST:
            move_player(world, player, player->x + 1, player->y);
            break;
        case SOUTH:
            move_player(world, player, player->x, player->y + 1);
            break;
        case WEST:
            move_player(world, player, player->x - 1, player->y);
            break;
    }
    set_response("ok\n");
    return (NO_ERROR);
}

int left_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    player->orientation--;
    set_response("ok\n");
    return (NO_ERROR);
}

int right_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    player->orientation++;
    set_response("ok\n");
    return (NO_ERROR);
}
