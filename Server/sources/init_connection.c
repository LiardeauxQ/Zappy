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
                sizeof(struct sockaddr_in)) == -1)
        exit_with_error("bind");
    return (sockaddr);
}

void init_connection(server_t *server)
{
    server->sockfd = socket(AF_INET, SOCK_STREAM, 6);

    if (server->sockfd == -1)
        exit_with_error("socket");
    server->sockaddr = bind_socket(server->sockfd, server->port);
}
