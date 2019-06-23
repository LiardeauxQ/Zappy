/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <fcntl.h>
#include <stdio.h>
#include <signal.h>

#include "arguments.h"
#include "graphical/commands.h"
#include "graphical/client.h"
#include "ai/protocols.h"
#include "ai/client.h"
#include "connection.h"
#include "server.h"
#include "client.h"
#include "unit_tests.h"

static info_t info = {0};

void sigint_handler(int __attribute__((unused)) sig) {
    destroy_info(&info);
    exit(0);
}

void check_connection(game_t *game, server_t *server, client_reader reader)
{
    struct timeval timeout = {0};
    int max_fd = 0;
    int sockfd = server->sockfd;
    fd_set readfds = server->readfds;
    int clt_sockfd = 0;

    timeout.tv_usec = 1000;
    max_fd = set_fds(&readfds, server->clients, sockfd);
    if (select(max_fd + 1, &readfds, 0x0, 0x0, &timeout) == -1)
        exit_with_error("select");
    clt_sockfd = get_new_connection(&readfds, &server->clients, sockfd);
    if (reader == &read_graph_client)
        send_graph_welcome(&game->world, server->clients, clt_sockfd);
    if (clt_sockfd > 0 && reader == &read_ai_client)
        write(clt_sockfd, WELCOME_MSG, WELCOME_MSG_LEN);
    else if (clt_sockfd > 0) {
        for (size_t i = 0 ; i < game->world.width ; i++)
            for (size_t j = 0 ; j < game->world.height ; j++)
                assign_tile_content(&game->world, i, j, clt_sockfd);
    }
    handle_clients(game, &server->clients, &readfds, reader);
}

int start_server(info_t *info)
{
    if (listen(info->server_ai.sockfd, MAX_CLIENT) == -1
            || listen(info->server_graph.sockfd, MAX_CLIENT) == -1)
        return (84);
    while (1) {
        check_connection(&info->game, &info->server_ai, &read_ai_client);
        check_connection(&info->game, &info->server_graph, &read_graph_client);
    }
    return (0);
}

int main(int ac, char **av)
{
    int return_value = 0;

    init_info(ac, av, &info);
    signal(SIGINT, sigint_handler);
    return_value = start_server(&info);
    destroy_info(&info);
    return (return_value);
}
