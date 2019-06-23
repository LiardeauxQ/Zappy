/*
** EPITECH PROJECT, 2018
** destroy_player.c
** File description:
** destroy player
*/

#include "linked_list.h"
#include "teams.h"
#include "world.h"
#include "player.h"

int remove_player(world_t *world, player_t *player)
{
    player_t *tmp = 0x0;
    size_t pos = 0;
    tile_content_t *tile = 0x0;

    for (node_t *node = world->players.head ; node
            ; node = node->next, pos++) {
        tmp = (player_t *)node->data;
        if (player->id == tmp->id)
            break;
    }
    pos = 0;
    tile = &world->tiles[player->x][player->y];
    for (node_t *node = tile->players_id.head; node; node = node->next, pos++) {
        if (*(unsigned int*) node->data == player->id) {
            delete_elem(&tile->players_id, pos);
            break;
        }
    }
    // delete_elem(&world->teams[player->team_id].players_id, pos);
    delete_elem(&world->players, pos);
    return (0);
}
