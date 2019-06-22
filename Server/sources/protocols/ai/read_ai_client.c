/*
** EPITECH PROJECT, 2018
** read_ai_client.c
** File description:
** catch clients commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ai/client.h"

void execute_action(client_t *client, game_t *game, const char **splitted_cmd)
{
    int action_found = 0;
    clock_t start_time = clock();
    act_handler_t *handler = 0x0;
    world_t world = game->world;
    player_t *player = get_player(world.players, client->client_nb);

    if (!player)
        return set_response("ko");
    for (int i = 0; !action_found && game->action_register.handlers[i]; i++) {
        handler = game->action_register.handlers[i];
        if (!strcmp(splitted_cmd[0], handler->command)) {
            handler->handler(&world, player, splitted_cmd + sizeof(char *));
            action_found = 1;
        }
    }
    if (!action_found)
        set_response("ko");
    while (action_found && !is_time_limit_reached(start_time,
                handler->limit_cycles, world.f));
}

void init_client_communication(client_t *clt, game_t *game)
{
    char *team_name = 0x0;
    char *client_id_str = 0x0;
    char *position = 0x0;
    player_t *player = 0x0;

    team_name = get_next_line(clt->sockfd);
    clt->client_nb = add_player(&game->world, 0);
    player = (player_t*)game->world.players.tail->data;
    asprintf(&client_id_str, "%d\n", clt->client_nb);
    write(clt->sockfd, client_id_str, strlen(client_id_str));
    asprintf(&position, "%d %d\n", player->x, player->y);
    write(clt->sockfd, position, strlen(position));
    free(position);
    free(client_id_str);
    free(team_name);
}

int read_ai_client(client_t *client, game_t *game)
{
    char *buffer = 0x0;
    char **splitted_cmd = 0x0;
    size_t line_len = 0;
    FILE *cfp = fdopen(client->sockfd, "r");

    hatch(&game->world, get_player(game->world.players, client->client_nb),
            game->world.f);
    if (client->client_nb == -1) {
        init_client_communication(client, game);
        return (0);
    }
    if (getline(&buffer, &line_len, cfp) < 0 || !buffer || !buffer[0])
        return (-1);
    buffer[strlen(buffer) - 1] = 0;
    splitted_cmd = str_to_tab(buffer, " ");
    execute_action(client, game, (const char **) splitted_cmd);
    printf("Send: %s\n", get_response());
    write(client->sockfd, get_response(), strlen(get_response()));
    free(buffer);
    return (0);
}
