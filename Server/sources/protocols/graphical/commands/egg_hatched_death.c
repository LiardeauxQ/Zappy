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

int assign_egg_hatched_egg(int egg_num, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[INT_SENDER_POS] = (sender_t){&egg_num, sizeof(int), sockfd, 0};
    senders[CUSTOM_SENDER_POS].is_last = 1;
    return (send_egg_hatched_death(convert_senders_to_data(senders)));
}

int send_egg_hatched_death(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_HATCHED_EGG_DEATH_LEN;
    srv_hatched_egg_death_t srv = {0};
    pkt_header_t hdr = {SRV_PLAYER_DEATH_EGG, PROTOCOL_VERSION,
        SRV_HATCHED_EGG_DEATH_LEN, 0};

    if (senders == 0x0)
        return (-1);
    srv.egg_num = *((int*)(senders[INT_SENDER_POS].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_HATCHED_EGG_DEATH_LEN);
    write(senders[INT_SENDER_POS].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (SRV_PLAYER_DEATH_EGG);
}
