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
#include "ai/handlers/init_action_handlers.h"

int init_info(int ac, char **av, info_t *info)
{       
    handle_arguments(ac, av, &info->input);
    parse_resources(info->input.resources_filename);
    init_packets(&info->game.handler_register);
    init_action_handler_register(&info->game.action_register);
    info->server_ai.port = (info->input.port == 0 ? DEFAULT_PORT_AI
            : info->input.port);
    info->server_graph.port = (info->input.port == 0 ? DEFAULT_PORT_GRAPH
            : info->input.port + 1);
    init_connection(&info->server_ai);
    init_non_blocking_connection(&info->server_graph);
    info->game.world.width = info->input.width;
    info->game.world.height = info->input.height;
    info->game.world.f = info->input.frequence;
    generate_world(&info->game.world, info->input.resources_filename);
    info->game.world.max_team_size = info->input.client_nbr;
    return (0);
}

void destroy_info(info_t *info)
{
    destroy_packets(&info->game.handler_register);
    free_input(&info->input);
    close(info->server_ai.sockfd);
    close(info->server_graph.sockfd);
}
