/*
** EPITECH PROJECT, 2018
** read_ai_client.c
** File description:
** catch clients commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphical/client.h"
#include "ai/client.h"
#include "ai/handlers/elevation_handler.h"
#include "ai/handlers/fork_handler.h"

void handle_awaiting_actions(int fd, world_t *world, player_t *player)
{
    if (!player)
        return;
    hatch(world, player);
    elevate(fd, world, player);
}

void init_client_communication(client_t *clt, game_t *game)
{
    char *team_name = 0x0;
    char *data = 0x0;
    char *position = 0x0;
    player_t *player = 0x0;

    team_name = get_next_line(clt->sockfd);
    clt->client_nb = add_player(&game->world, 0);
    player = (player_t*) game->world.players.tail->data;
    asprintf(&data, "%d\n%d %d\n", clt->client_nb, player->x, player->y);
    write(clt->sockfd, data, strlen(data));
    free(position);
    free(data);
    free(team_name);
}

void execute_action(client_t __attribute__((unused))*client,
        game_t *game, player_t *player,
        const char **splitted_cmd)
{
    int action_found = 0;
    clock_t start_time = clock();
    act_handler_t *handler = 0x0;
    world_t world = game->world;

    if (!player)
        return set_response("ko");
    for (int i = 0; !action_found && game->action_register.handlers[i]; i++) {
        handler = game->action_register.handlers[i];
        if (!strcmp(splitted_cmd[0], handler->command)) {
            handler->handler(&world, player, splitted_cmd + 1);
            action_found = 1;
        }
    }
    if (!action_found)
        set_response("ko");
    while (action_found && handler->limit_cycles != -1 &&
            !is_time_limit_reached(start_time,
                handler->limit_cycles, world.f));
}

void display_actions_log(player_t *player, char *action)
{
    printf("==> Player (id: %d, team: %d): { x: %d, y: %d }\n", player->id,
            player->team_id, player->x, player->y);
    printf("    -> Cmd: %s\n       Send: %s\n", action, get_response());
}

int read_ai_client(client_t *client, game_t *game)
{
    char *buffer = 0x0;
    char **splitted_cmd = 0x0;
    size_t line_len = 0;
    FILE *cfp = fdopen(client->sockfd, "r");
    player_t *player = get_player(game->world.players, client->client_nb);

    if (client->client_nb == -1) {
        init_client_communication(client, game);
        return (0);
    }
    if (getline(&buffer, &line_len, cfp) < 0 || !buffer || !buffer[0])
        return (-1);
    buffer[strlen(buffer) - 1] = 0;
    splitted_cmd = str_to_tab(buffer, " ");
    printf("==> %p %p %p %p\n", client, game, player, splitted_cmd);
    execute_action(client, game, player, (const char **) splitted_cmd);
    display_actions_log(player, buffer);
    write(client->sockfd, get_response(), strlen(get_response()));
    // if (is_graph_request_ok())
        // exec_graph_request();
    free(buffer);
    return (0);
}
