/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "server.h"
#include "arguments.h"
#include "graphical/commands.h"
#include "connection.h"

void start_server(client_t (*clients)[MAX_CLIENT], int const sockfd)
{
    int max_fd = 0;
    fd_set readfds = {0};

    if (listen(sockfd, MAX_CLIENT) == -1)
        exit_with_error("listen");
    while (1) {
        max_fd = set_fds(&readfds, *clients, sockfd);
        if (select(max_fd + 1, &readfds, 0x0, 0x0, 0x0) == -1)
            exit_with_error("select");
        get_new_connection(&readfds, clients, sockfd);
        handle_clients(clients, &readfds);
        //TODO: communication between server and client with the protocol
    }
}

int main(int ac, char **av)
{
    info_t info = {0};
    client_t clients[MAX_CLIENT] = {0};

    handle_arguments(ac, av, &info.input);
    parse_resources(info.input.resources_filename);
    //info.server.port = info.input.port;
    //init_connection(&info.server);
    //start_server(&clients, info.server.sockfd);
    destroy_server_info(&info);
    return (0);
}
