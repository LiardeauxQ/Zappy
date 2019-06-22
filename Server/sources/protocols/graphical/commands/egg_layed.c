/*
** EPITECH PROJECT, 2018
** egg_layed.c
** File description:
** handle layed egg
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

int assign_layed_egg(player_t *player, int egg_num, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[PLAYER_SENDER_POS] = (sender_t){player, sizeof(player_t),
        sockfd, 0};
    senders[INT_SENDER_POS] = (sender_t){&egg_num, sizeof(int), sockfd, 0};
    senders[CUSTOM_SENDER_POS].is_last = 1;
    return (send_layed_egg(convert_senders_to_data(senders)));
}

int send_layed_egg(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_EGG_LAYED_LEN;
    srv_player_egg_layed_t srv = {0};
    player_t *player = 0x0;
    pkt_header_t hdr = {SRV_EGG_LAYED, PROTOCOL_VERSION,
        SRV_PLAYER_EGG_LAYED_LEN, 0};

    if (senders == 0x0)
        return (-1);
    player = (player_t*)(senders[PLAYER_SENDER_POS].data);
    srv = (srv_player_egg_layed_t){player->id, 0, player->x, player->y};
    srv.egg_num = *((int*)(senders[INT_SENDER_POS].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_PLAYER_EGG_LAYED_LEN);
    write(senders[PLAYER_SENDER_POS].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (SRV_EGG_LAYED);
}
