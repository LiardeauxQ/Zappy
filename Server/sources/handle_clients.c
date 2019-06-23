/*
** EPITECH PROJECT, 2018
** handle_clients.c
** File description:
** handle clients interaction
*/

#include <stdio.h>

#include "server.h"
#include "client.h"
#include "ai/handlers/utils.h"
#include "ai/client.h"

void handle_clients(game_t *game, client_t (*clients)[MAX_CLIENT],
        fd_set *readfds, client_reader reader)
{
    int fd = 0;
    int result = 0;
    player_t *player = 0x0;

    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = (*clients)[i].sockfd;
        if ((*clients)[i].type == AI && (*clients)[i].client_nb != -1) {
            player = get_player(game->world.players, (*clients)[i].client_nb);
            handle_awaiting_actions(fd, &game->world, player);
        }
        if (!FD_ISSET(fd, readfds))
            continue;
        result = reader(&(*clients)[i], game);
        if (result == CLT_CLOSE_CONNECTION)
            FD_CLR(fd, readfds);
    }
}
