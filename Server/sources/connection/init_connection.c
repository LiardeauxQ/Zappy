/*
** EPITECH PROJECT, 2018
** init_connection.c
** File description:
** init server connection
*/

#include <fcntl.h>
#include <arpa/inet.h>

#include "server.h"
#include "connection.h"
#include "error.h"

static struct sockaddr_in bind_socket(int const sockfd, int const port)
{
    struct sockaddr_in sockaddr = {0};

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    sockaddr.sin_addr.s_addr = htons(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&sockaddr,
                sizeof(struct sockaddr_in)) == -1) {
        print_exit_msg("Error with bind", 0);
        memset(&sockaddr, 0, sizeof(sockaddr));
    }
    return (sockaddr);
}

int init_connection(server_t *server)
{
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (server->sockfd == -1)
        return (print_exit_msg("Error with socket initialization", -1));
    server->sockaddr = bind_socket(server->sockfd, server->port);
    return (server->sockfd);
}

int init_non_blocking_connection(server_t *server)
{
    int sockfd = init_connection(server);
    int flags = 0;

    if (server->sockfd == -1)
        return (print_exit_msg("Error with socket initialization", -1));
    flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    return (sockfd);
}

int set_fds(fd_set *readfds, client_t const clients[MAX_CLIENT],
    int const sockfd)
{
    int fd = 0;
    int max_fd = 0;

    FD_ZERO(readfds);
    FD_SET(sockfd, readfds);
    max_fd = sockfd;
    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        fd = clients[i].sockfd;
        if (fd > 0)
            FD_SET(fd, readfds);
        if (fd > max_fd)
            max_fd = fd;
    }
    return (max_fd);
}

int get_new_connection(fd_set *readfds, client_t (*clients)[MAX_CLIENT],
    int const main_socket)
{
    int new_socket = 0;
    struct sockaddr_in addr = {0};
    socklen_t addrlen = sizeof(addr);

    if (!FD_ISSET(main_socket, readfds))
        return (0);
    new_socket = accept(main_socket, (struct sockaddr*)&addr, &addrlen);
    if (new_socket == -1) {
        perror("accept");
        return (-1);
    }
    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        if ((*clients)[i].sockfd == 0) {
            (*clients)[i] = (client_t){new_socket, -1, addr};
            break;
        }
    }
    printf("Connection on socket %d with address %s\n", new_socket,
            inet_ntoa(addr.sin_addr));
    return (new_socket);
}
