/*
** EPITECH PROJECT, 2018
** player_info_handlers.c
** File description:
** Handle every action on player informations.
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "ai/handlers/broadcast_handler.h"

void broadcast(client_t (*clients)[MAX_CLIENT], world_t *world,
        player_t *player)
{
    int k = 0;
    char *res = 0x0;
    player_t *tmp = 0x0;

    if (!player->broadcast_text)
        return;
    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        if ((*clients)[i].client_nb == (int) player->id ||
                (*clients)[i].type != AI || (*clients)[i].client_nb == -1)
            continue;
        tmp = get_player(world->players,
                (*clients)[i].client_nb);
        k = getBroadcastTile(world, player, tmp);
        k += ((tmp->orientation - 1) * 2) % 8;
        asprintf(&res, "message %d, %s\n", k, player->broadcast_text);
        if ((*clients)[i].sockfd)
            write((*clients)[i].sockfd, res, strlen(res));
        free(res);
    }
    free(player->broadcast_text);
    player->broadcast_text = 0x0;
}

int getBroadcastTile(world_t *world, player_t *src_player, player_t *dest_player)
{
    pos_t src_player_pos = {src_player->x, src_player->y};
    pos_t dest_player_pos = {dest_player->x, dest_player->y};
    pos_t tmp_player_pos = {0};
    unsigned int tangente = 0;
    unsigned int alpha = 0;

    if (src_player_pos.x == dest_player_pos.x &&
            src_player_pos.y == dest_player_pos.y)
        return (0);
    if ((size_t) src_player_pos.x - dest_player_pos.x > world->width / 2)
        dest_player_pos.x += world->width;
    if ((size_t) src_player_pos.y - dest_player_pos.y > world->height / 2)
        dest_player_pos.y += world->height;
    tmp_player_pos.x = src_player_pos.x;
    tmp_player_pos.y = dest_player_pos.y;
    tangente = tmp_player_pos.x / tmp_player_pos.y;
    alpha = atan(tangente);
    alpha = (dest_player_pos.y > src_player_pos.y) ? alpha + 180 : alpha;
    return ((alpha - 22.5) / 45 + 1);
}

int broadcast_handler(world_t __attribute__((unused)) *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    if (!args || !args[0])
        return (TOO_FEW_PARAMETERS);
    else if (args[1])
        return (TOO_MUCH_PARAMETERS);
    player->broadcast_text = calloc(1, sizeof(char) * (strlen(args[0]) + 1));
    strcpy(player->broadcast_text, args[0]);
    set_response("ok\n");
    return (NO_ERROR);
}
