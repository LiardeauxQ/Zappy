/*
** EPITECH PROJECT, 2018
** read_ai_client.c
** File description:
** catch clients commands
*/

#include <stdio.h>
#include <string.h>

#include "server.h"
#include "utils.h"
#include "player.h"
#include "ai/client.h"

void init_client_communication(client_t *clt, game_t *game)
{
    char *team_name = 0x0;
    char *client_num = 0x0;
    char *position = 0x0;
    player_t *player = 0x0;

    team_name = get_next_line(clt->sockfd);
    clt->client_nb = add_player(&game->world, 0);
    player = (player_t*)game->world.players.tail->data;
    asprintf(&client_num, "%d\n", 6);
    write(clt->sockfd, client_num, strlen(client_num));
    asprintf(&position, "%d %d\n", player->x, player->y);
    write(clt->sockfd, position, strlen(position));
    free(position);
    free(client_num);
    free(team_name);
}

int read_ai_client(client_t *clt, game_t *g)
{
    char *buffer = 0x0;

    if (clt->client_nb == -1) {
        init_client_communication(clt, g);
        return (0);
    }
    buffer = get_next_line(clt->sockfd);
    printf("%s\n", buffer);
    write(clt->sockfd, "KO\n", 3);
    free(buffer);
    return (0);
}
