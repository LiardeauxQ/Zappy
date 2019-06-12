/*
** EPITECH PROJECT, 2018
** name
** File description:
** test init connection functions
*/

#include <criterion/criterion.h>
#include "server.h"
#include "connection.h"

Test(init_connection, test_simple_connection)
{
      server_t server = {0};

    server.port = 5660;
    init_connection(&server);
    cr_assert_neq(server.sockfd, -1);
    cr_assert_eq(server.sockaddr.sin_port, htons(server.port));
    cr_assert_eq(server.sockaddr.sin_family, AF_INET);
    cr_assert_eq(server.sockaddr.sin_addr.s_addr, htons(INADDR_ANY));
    close(server.sockfd);
}
