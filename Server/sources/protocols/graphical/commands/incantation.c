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
fill_start_incantation_struct(const player_t *player, const world_t *world)
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

int send_incantation_start(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_START_INCANTATION_LEN;
    srv_start_incantation_t srv = {0};
    pkt_header_t hdr = {SRV_INCANTATION_START, PROTOCOL_VERSION,
        SRV_START_INCANTATION_LEN, 0};
    world_t *world = 0x0;
    player_t *player = 0x0;

    if (count_senders(senders) != 2)
        return (-1);
    world = (world_t*)(senders[1].data);
    player = (player_t*)(senders[1].data);
    srv = fill_start_incantation_struct(player, world);
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_START_INCANTATION_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}

int send_incantation_end(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_END_INCANTATION_LEN;
    srv_end_incantation_t *srv = 0x0;
    pkt_header_t hdr = {SRV_INCANTATION_END, PROTOCOL_VERSION,
        SRV_END_INCANTATION_LEN, 0};

    if (count_senders(senders) != 1)
        return (-1);
    srv = (srv_end_incantation_t*)senders[0].data;
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_END_INCANTATION_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}
