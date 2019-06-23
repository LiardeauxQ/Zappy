/*
** EPITECH PROJECT, 2018
** elevation_handler.c
** File description:
** Handle elevation
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>

#include "ai/handlers/elevation_handler.h"

///
/// Rules to authorize or not the elevation of a player
/// The first dimension associates a set of rules with a level. 
/// For example, a user who want to elevate from level 1 to 2 should look at
///   elevation_rules[0].
/// The rules are organised following the following scheme:
///   Number of player, Linemate, Deraumere, Sibur, Mendiane, Phiras, Thystame
///
static int elevation_rules[7][7] = {
    {
        1, 1, 0, 0, 0, 0, 0
    }, {
        2, 1, 1, 1, 0, 0, 0
    }, {
        2, 2, 0, 1, 0, 2, 0
    }, {
        4, 1, 1, 2, 0, 1, 0
    }, {
        4, 1, 2, 1, 3, 0, 0
    }, {
        6, 1, 2, 3, 0, 1, 0
    }, {
        6, 2, 2, 2, 2, 2, 1
    }
};

void elevate(int client_fd, world_t *world, player_t *player)
{
    int sockfd = (get_graph_clients())[0].sockfd;
    char *res = 0x0;

    if (!player->elevation_start_time)
        return;
    if (is_time_limit_reached(player->elevation_start_time,
                ELEVATION_TIME, world->f)) {
        player->level += 1;
        res = calloc(1, strlen("Current level: k\n") + 1);
        strcat(res, "Current level: ");
        sprintf(res + strlen("Current level: "), "%d\n", player->level);
        write(client_fd, res, strlen(res));
        free(res);
        player->elevation_start_time = 0;
        set_graph_request(assign_player_level(world, &player->id, sockfd),
            &send_player_level);
    }
}

int is_enough_users(world_t *world, tile_content_t *tile, player_t *player)
{
    int i = 0;
    player_t *tmp_player = 0x0;
    node_t *player_id_cursor = tile->players_id.head;

    for (; player_id_cursor; player_id_cursor = player_id_cursor->next) {
        tmp_player = get_player(world->players,
                *(unsigned int*) player_id_cursor->data);
        if (tmp_player->level == player->level)
            i++;
    }
    if (i < elevation_rules[player->level - 1][0])
        return (0);
    return (1);
}

int elevation_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    int sockfd = (get_graph_clients())[0].sockfd;
    tile_content_t tile = world->tiles[player->x][player->y];

    if (!is_enough_users(world, &tile, player)) {
        printf("User KO\n");
        set_response("ko\n");
        return (INVALID_PARAMETERS);
    }
    for (int i = 1; tile.resources[i] != -1 &&
            i < DEFAULT_RESOURCES_NUMBER - 1; i++) {
        if (tile.resources[i] < elevation_rules[player->level - 1][i]) {
            printf("Ressources KO\n");
            set_response("ko\n");
            return (INVALID_PARAMETERS);
        }
    }
    player->elevation_start_time = clock();
    set_response("Elevation underway\n");
    send_incantation_start(assign_incantation_start(world, player, sockfd));
    set_graph_request(assign_incantation_end(player->x, player->y, OK, sockfd),
        &send_incantation_end);
    return (NO_ERROR);
}
