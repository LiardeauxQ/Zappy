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

//    start_server(&info);
    destroy_info(&info);
size_t size = PKT_HDR_LEN + SRV_TILE_CONTENT_LEN + 1;
    int ressources[DEFAULT_RESOURCES_NUMBER + 1] = {0, 1, 2, 3, 4, 5, 6, -1};
    int player_nb = 9;
    world_t world = {0};
    int fd = open("tmp", O_CREAT | O_RDWR, 0644);
    char buffer[80] = {0};
    char result[PKT_HDR_LEN + SRV_TILE_CONTENT_LEN + 1] = {0};
    pkt_header_t hdr = {14, PROTOCOL_VERSION, SRV_TILE_CONTENT_LEN, 1};
    srv_tile_content_t tile = {0, 0, 0, 1, 2, 3, 4, 5, 6, player_nb};

    world.width = 1;
    world.height = 1;
    world.tiles = init_tiles(1, 1, DEFAULT_RESOURCES_NUMBER);
    world.tiles[0][0].resources = ressources;
    world.tiles[0][0].player_nb = player_nb;

    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &tile, SRV_TILE_CONTENT_LEN);
    read(fd, buffer, size);
    printf("test\n");
    return (0);
}
