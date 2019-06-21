/*
** EPITECH PROJECT, 2018
** init_info.c
** File description:
** init info structure
*/

#include "server.h"
#include "arguments.h"
#include "resources.h"
#include "connection.h"
#include "graphical/packets.h"

info_t init_info(int ac, char **av)
{       
    info_t info = {0};

    handle_arguments(ac, av, &info.input);
    parse_resources(info.input.resources_filename);
    init_packets(&info.game.handler_register);
    info.server_ai.port = (info.input.port == 0 ? DEFAULT_PORT_AI
            : info.input.port);
    info.server_graph.port = (info.input.port == 0 ? DEFAULT_PORT_GRAPH
            : info.input.port + 1);
    init_connection(&info.server_ai);
    init_connection(&info.server_graph);
    info.game.world = generate_world(info.input.width, info.input.height,
            info.input.frequence, info.input.resources_filename);
    return (info);
}

void destroy_info(info_t *info)
{
    destroy_packets(&info->game.handler_register);
    free_input(&info->input);
    close(info->server_ai.sockfd);
    close(info->server_graph.sockfd);
}
