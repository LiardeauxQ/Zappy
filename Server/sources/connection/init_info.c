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
    init_packets(&info.handler_register);
    info.server.port = info.input.port;
    init_connection(&info.server);
    return (info);
}

void destroy_info(info_t *info)
{
    destroy_packets(&info->handler_register);
    free_input(&info->input);
    close(info->server.sockfd);
}
