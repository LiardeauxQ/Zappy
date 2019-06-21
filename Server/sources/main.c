/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <fcntl.h>
#include <stdio.h>

#include "arguments.h"
#include "graphical/commands.h"
#include "ai/protocols.h"
#include "connection.h"
#include "server.h"

void check_connection(game_t *game, server_t *server)
{
    int max_fd = 0;
    int sockfd = server->sockfd;
    fd_set readfds = server->readfds;

    max_fd = set_fds(&readfds, server->clients, sockfd);
    if (select(max_fd + 1, &readfds, 0x0, 0x0, 0x0) == -1)
        exit_with_error("select");
    if (get_new_connection(&readfds, &server->clients, sockfd) == 1)
        write(sockfd, WELCOME_MSG, WELCOME_MSG_LEN);
    handle_clients(game, &server->clients, &readfds);
}

void start_server(info_t *info)
{
    if (listen(info->server_ai.sockfd, MAX_CLIENT) == -1
            || listen(info->server_graph.sockfd, MAX_CLIENT) == -1)
        exit_with_error("listen");
    while (1) {
        check_connection(&info->game, &info->server_ai);
        check_connection(&info->game, &info->server_graph);
    }
}

int main(int ac, char **av)
{
    info_t info = init_info(ac, av);

    start_server(&info);
    destroy_info(&info);
    return (0);
}
