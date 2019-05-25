/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "server.h"
#include "arguments.h"
#include "connection.h"

void start_server(struct client_s (*clients)[MAX_CLIENT], int const sockfd)
{
    int max_fd = 0;
    fd_set readfds = {0};

    while (1) {
        max_fd = set_fds(&readfds, *clients, sockfd);
        if (select(max_fd + 1, &readfds, 0x0, 0x0, 0x0) == -1)
            exit_with_error("select");
        get_new_connection(&readfds, clients, sockfd);
        //TODO: communication between server and client with the protocol
    }
}

int main(int ac, char **av)
{
    info_t info = {0};

    handle_arguments(ac, av, &info.input);
    info.server.port = info.input.port;
    init_connection(&info.server);
    destroy_server_info(&info);
    return (0);
}
