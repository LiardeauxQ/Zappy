/*
** EPITECH PROJECT, 2018
** handle_resources.c
** File description:
** handle resources
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

void *assign_resource_drop(int *player_num, enum RESOURCE_NUMBER *resource,
        int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[INT_SENDER_POS] = (sender_t){player_num, sizeof(int), sockfd, 0};
    senders[CUSTOM_SENDER_POS] = (sender_t){resource,
        sizeof(enum RESOURCE_NUMBER), sockfd, 1};
    return (convert_senders_to_data(senders));
}

int send_resource_drop(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_RESOURCE_DROPPED_LEN;
    srv_player_resource_dropped_t srv = {0};
    pkt_header_t hdr = {SRV_RESOURCE_DROP, PROTOCOL_VERSION,
        SRV_PLAYER_RESOURCE_DROPPED_LEN, 0};

    if (senders == 0x0)
        return (-1);
    srv.player_num = *((int*)(senders[INT_SENDER_POS].data));
    srv.resource = *(int*)(senders[CUSTOM_SENDER_POS].data);
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_PLAYER_RESOURCE_DROPPED_LEN);
    write(senders[INT_SENDER_POS].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (SRV_RESOURCE_DROP);
}

void *assign_resource_collect(int *player_num, enum RESOURCE_NUMBER *resource,
        int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[INT_SENDER_POS] = (sender_t){player_num, sizeof(int), sockfd, 0};
    senders[CUSTOM_SENDER_POS] = (sender_t){resource,
        sizeof(enum RESOURCE_NUMBER), sockfd, 1};
    return (convert_senders_to_data(senders));
}

int send_resource_collect(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_RESOURCE_COLLECTED_LEN;
    srv_player_resource_collected_t srv = {0};
    pkt_header_t hdr = {SRV_RESOURCE_COLLECT, PROTOCOL_VERSION,
        SRV_PLAYER_RESOURCE_COLLECTED_LEN, 0};

    if (senders == 0x0)
        return (-1);
    srv.player_num = *((int*)(senders[INT_SENDER_POS].data));
    srv.resource = *(int*)(senders[CUSTOM_SENDER_POS].data);
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_PLAYER_RESOURCE_COLLECTED_LEN);
    write(senders[INT_SENDER_POS].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (SRV_RESOURCE_COLLECT);
}
