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
#include "connection.h"
#include "server.h"

void start_server(info_t *info)
{
    int sockfd = info->server.sockfd;
    int max_fd = 0;
    fd_set readfds = {0};

    if (listen(sockfd, MAX_CLIENT) == -1)
        exit_with_error("listen");
    while (1) {
        max_fd = set_fds(&readfds, info->clients, sockfd);
        if (select(max_fd + 1, &readfds, 0x0, 0x0, 0x0) == -1)
            exit_with_error("select");
        get_new_connection(&readfds, &info->clients, sockfd);
        handle_clients(info, &readfds);
        //TODO: communication between server and client with the protocol
    }
}

int main(int ac, char **av)
{
    info_t info = init_info(ac, av);

    start_server(&info);
    destroy_info(&info);
    return (0);
}
