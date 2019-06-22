/*
** EPITECH PROJECT, 2018
** handle_incantation.c
** File description:
** handle incantation
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

static srv_start_incantation_t
fill_start_incantation_struct(const player_t *player, world_t *world)
{
    srv_start_incantation_t incantation = {0};
    player_t *tmp_player = 0x0;
    size_t i = 0;

    incantation.x = player->x;
    incantation.y = player->x;
    incantation.level = player->level;
    for (node_t *tmp = world->players.head ; tmp && i < 32 ; tmp = tmp->next) {
        tmp_player = (player_t*)tmp->data;
        incantation.players[i] = tmp_player->id;
        i += 1;
    }
    return (incantation);
}

int assign_incantation_start(world_t *world, player_t *player, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[WORLD_SENDER_POS] = (sender_t){world, sizeof(world_t), sockfd, 0};
    senders[PLAYER_SENDER_POS] = (sender_t){player, sizeof(player_t),
        sockfd, 0};
    senders[CUSTOM_SENDER_POS].is_last = 1;
    return (send_incantation_start(convert_senders_to_data(senders)));
}

int send_incantation_start(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    world_t *world = 0x0;
    player_t *player = 0x0;
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_START_INCANTATION_LEN;
    pkt_header_t hdr = {SRV_INCANTATION_START, PROTOCOL_VERSION,
        SRV_START_INCANTATION_LEN, 0};
    srv_start_incantation_t srv = {0};

    if (senders == 0x0)
        return (-1);
    world = (world_t*)(senders[WORLD_SENDER_POS].data);
    player = (player_t*)(senders[PLAYER_SENDER_POS].data);
    srv = fill_start_incantation_struct(player, world);
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_START_INCANTATION_LEN);
    write(senders[WORLD_SENDER_POS].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (SRV_INCANTATION_START);
}

int assign_incantation_end(unsigned int x, unsigned int y,
        enum RESULT result, int sockfd)
{
    srv_end_incantation_t srv = {x, y, result};
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[CUSTOM_SENDER_POS] = (sender_t){&srv,
        sizeof(srv_end_incantation_t), sockfd, 1};
    return (send_incantation_end(convert_senders_to_data(senders)));
}

int send_incantation_end(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_END_INCANTATION_LEN;
    srv_end_incantation_t *srv = 0x0;
    pkt_header_t hdr = {SRV_INCANTATION_END, PROTOCOL_VERSION,
        SRV_END_INCANTATION_LEN, 0};

    if (senders == 0x0)
        return (-1);
    srv = (srv_end_incantation_t*)senders[CUSTOM_SENDER_POS].data;
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, srv, SRV_END_INCANTATION_LEN);
    write(senders[CUSTOM_SENDER_POS].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (SRV_INCANTATION_END);
}
