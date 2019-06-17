/*
** EPITECH PROJECT, 2018
** init_connection.c
** File description:
** init server connection
*/

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
    return (0);
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

void get_new_connection(fd_set *readfds, client_t (*clients)[MAX_CLIENT],
    int const main_socket)
{
    int new_socket = 0;
    struct sockaddr addr = {0};
    socklen_t addrlen = sizeof(addr);

    if (!FD_ISSET(main_socket, readfds))
        return;
    new_socket = accept(main_socket, &addr, &addrlen);
    if (new_socket == -1) {
        perror("accept");
        return;
    }
    for (int i = 0 ; i < MAX_CLIENT ; i++) {
        if ((*clients)[i].sockfd == 0) {
            (*clients)[i].sockfd = new_socket;
            break;
        }
    }
}
