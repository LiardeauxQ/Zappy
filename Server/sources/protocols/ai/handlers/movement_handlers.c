/*
** EPITECH PROJECT, 2018
** movement_handlers.c
** File description:
** Handle every moves made by the player.
*/

#include "ai/handlers/movement_handlers.h"

void move_player(world_t *world, player_t *player, pos_t *pos)
{
    int is_found = 0;
    tile_content_t *tile = &world->tiles[player->x][player->y];
    tile_content_t *dest_tile = &world->tiles[pos->x][pos->y];
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
        player->x = pos->x;
        player->y = pos->y;
    }
}

int forward_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    int sockfd = (get_graph_clients())[0].sockfd;
    pos_t current_pos = {player->x, player->y};

    next_case(world, &current_pos, player->orientation, 1);
    move_player(world, player, &current_pos);
    set_response("ok\n");
    set_graph_request(assign_player_position(world, &player->id, sockfd),
        &send_player_position);
    return (NO_ERROR);
}

int left_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    int sockfd = (get_graph_clients())[0].sockfd;

    if (player->orientation == 1)
        player->orientation = 4;
    else
        player->orientation--;
    set_response("ok\n");
    set_graph_request(assign_player_position(world, &player->id, sockfd),
        &send_player_position);
    return (NO_ERROR);
}

int right_move_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    int sockfd = (get_graph_clients())[0].sockfd;

    if (player->orientation == 4)
        player->orientation = 1;
    else
        player->orientation++;
    set_response("ok\n");
    set_graph_request(assign_player_position(world, &player->id, sockfd),
        &send_player_position);
    return (NO_ERROR);
}
