/*
** EPITECH PROJECT, 2018
** read_ai_client.c
** File description:
** catch clients commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"
#include "utils.h"
#include "player.h"
#include "manage_response.h"
#include "ai/protocols.h"
#include "ai/client.h"
#include "ai/handlers/utils.h"

void execute_action(client_t *client, game_t *game, const char **splitted_cmd)
{
    clock_t start_time = clock();

    act_handler_t *handler = 0x0;
    world_t world = game->world;
    player_t *player = get_player(world.players, client->client_nb);

    if (!player) {
        set_response("ko");
        return;
    }
    for (int i = 0; game->action_register.handlers[i]; i++) {
        handler = game->action_register.handlers[i];
        if (!strcmp(splitted_cmd[0], handler->command))
            handler->handler(&world, player, splitted_cmd + sizeof(char *));
    }
    while (!is_time_limit_reached(start_time,
                handler->limit_cycles, world.f));
}

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

int read_ai_client(client_t *client, game_t *game)
{
    char *buffer = 0x0;
    char **splitted_cmd = 0x0;
    size_t line_len = 0;
    FILE *cfp = fdopen(client->sockfd, "r");

    if (client->client_nb == -1) {
        init_client_communication(client, game);
        return (0);
    }
    if (getline(&buffer, &line_len, cfp) < 0 || !buffer || !buffer[0])
        return (-1);
    buffer[strlen(buffer) - 1] = 0;
    splitted_cmd = str_to_tab(buffer, " ");
    execute_action(client, game, (const char **) splitted_cmd);
    write(client->sockfd, get_response(), strlen(get_response()));
    free(buffer);
    return (0);
}
