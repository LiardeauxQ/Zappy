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

void execute_action(client_t *client, game_t *game, const char **splitted_cmd);

void init_client_communication(client_t *clt, game_t *game);

int read_ai_client(client_t *clt, game_t *g);
