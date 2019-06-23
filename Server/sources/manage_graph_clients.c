/*
** EPITECH PROJECT, 2018
** manage_graph_clients.c
** File description:
** Manage graph clients
*/

#include "manage_graph_clients.h"
#include "graphical/commands.h"

static client_t *manage_graph_clients(int option, client_t *clients)
{
    static client_t *graph_clients = 0x0;

    if (option)
        graph_clients = clients;
    return (graph_clients);
}

client_t *get_graph_clients(void)
{
    return (manage_graph_clients(0, 0x0));
}

void set_graph_clients(client_t *clients)
{
    manage_graph_clients(1, clients);
}

void send_graph_welcome(world_t *world, client_t *clients, int sockfd)
{
    printf("size %d %d\n", world->width, world->height);
    send_map_size(assign_map_size(world, sockfd));
    printf("map content 1\n");
    void *data = assign_map_content(world, sockfd);
    printf("map content 2\n");
    send_map_content(data);
    printf("map content 3\n");
    manage_graph_clients(1, clients);
}
