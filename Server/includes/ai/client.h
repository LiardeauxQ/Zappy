/*
** EPITECH PROJECT, 2018
** client.h
** File description:
** ai client header
*/

#pragma once

#include "server.h"
#include "utils.h"
#include "player.h"
#include "manage_response.h"
#include "ai/protocols.h"
#include "ai/handlers/fork_handler.h"
#include "ai/handlers/utils.h"

typedef struct client_s client_t;
typedef struct game_s game_t;

void handle_awaiting_actions(client_t (*clients)[MAX_CLIENT], int client_pos,
        world_t *world);

void init_client_communication(client_t *clt, game_t *game);

void execute_action(client_t *client, game_t *game, player_t *player,
        const char **splitted_cmd);

void display_actions_log(player_t *player, char *action);

void handle_awaiting_actions(int fd, world_t *world, player_t *player);
int read_ai_client(client_t *clt, game_t *g);
