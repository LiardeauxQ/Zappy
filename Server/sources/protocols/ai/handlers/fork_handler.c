/*
** EPITECH PROJECT, 2018
** fork_handler.c
** File description:
** Handler client fork
*/

#include "ai/handlers/fork_handler.h"

void hatch(world_t *world, player_t *player)
{
    int sockfd = 0;
    char *data = 0x0;

    if (!player->hatch_start_time)
        return;
    if (is_time_limit_reached(player->hatch_start_time,
                HATCH_TIME, world->f)) {
        sockfd = (get_graph_clients())[0].sockfd;
        world->max_team_size += 1;
        player->hatch_start_time = 0;
        data = assign_hatching_egg(player->id, sockfd);
        send_hatching_egg(data);
    }
}
int fork_handler(world_t *world, player_t *player,
        const char __attribute__((unused)) **args)
{
    int sockfd = (get_graph_clients())[0].sockfd;

    player->hatch_start_time = clock();
    send_laying_egg(assign_laying_egg(player->id, sockfd));
    set_response("ok\n");
    set_graph_request(assign_layed_egg(player, player->id, sockfd),
            &send_layed_egg);
    return (NO_ERROR);
}
