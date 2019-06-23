/*
** EPITECH PROJECT, 2018
** elevation_handlers.c
** File description:
** Elevation handlers - Unit Tests
*/

#include <criterion/criterion.h>

#include "server.h"
#include "ai/handlers/elevation_handler.h"

world_t *wrap_action_handlers()
{
    const char *args[] = {NULL};
    info_t info = {0};
    world_t world = {0};

    init_info(1, args, &info);
    set_graph_clients(info.server_graph.clients);
    generate_world(&world, 0x0);
    world.width = 4;
    world.height = 4;
    add_player(&world, 0);
    add_player(&world, 1);
}
