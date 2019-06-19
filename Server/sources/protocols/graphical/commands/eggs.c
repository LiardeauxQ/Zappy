/*
** EPITECH PROJECT, 2018
** handle_eggs.c
** File description:
** handle eggs
*/
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

int send_laying_egg(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_LAYING_LEN;
    srv_player_egg_laying_t srv = {0};
    pkt_header_t hdr = {SRV_EGG_LAYING, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_LAYING_LEN, 0};

    if (count_senders(senders) != 2)
        return (-1);
    srv.player_num = *((int*)(senders[1].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_PLAYER_EGG_LAYING_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}

int send_layed_egg(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_LAYED_LEN;
    srv_player_egg_layed_t srv = {0};
    player_t *player = 0x0;
    pkt_header_t hdr = {SRV_EGG_LAYED, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_LAYED_LEN, 0};

    if (count_senders(senders) != 3)
        return (-1);
    player = (player_t*)(senders[1].data);
    srv = (srv_player_egg_layed_t){player->id, 0, player->x, player->y};
    srv.egg_num = *((int*)(senders[2].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_PLAYER_EGG_LAYED_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}

int send_hatching_egg(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_HATCHING_LEN;
    srv_player_egg_hatching_t srv = {0};
    pkt_header_t hdr = {SRV_EGG_HATCHING, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_HATCHING_LEN, 0};

    if (count_senders(senders) != 2)
        return (-1);
    srv.egg_num = *((int*)(senders[1].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_PLAYER_EGG_HATCHING_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}

int send_egg_connection(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_CONNECTION_LEN;
    srv_player_egg_connection_t srv = {0};
    pkt_header_t hdr = {SRV_PLAYER_CONNECT_EGG, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_CONNECTION_LEN, 0};

    if (count_senders(senders) != 2)
        return (-1);
    srv.egg_num = *((int*)(senders[1].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_PLAYER_EGG_CONNECTION_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}

int send_egg_hatched_death(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_HATCHED_EGG_DEATH_LEN;
    srv_hatched_egg_death_t srv = {0};
    pkt_header_t hdr = {SRV_PLAYER_DEATH_EGG, PROTOCOL_VERSION,
        SRV_HATCHED_EGG_DEATH_LEN, 0};

    if (count_senders(senders) != 2)
        return (-1);
    srv.egg_num = *((int*)(senders[1].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_HATCHED_EGG_DEATH_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}
