/*
** EPITECH PROJECT, 2018
** handle_player_position.c
** File description:
** handle player's position
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

int get_player_position(const void __attribute__((unused)) *data)
{
    return (0);
}

int assign_player_position(world_t *world, unsigned int player_num,
        int sockfd)
{
    clt_player_pos_t pos = {player_num};
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[WORLD_SENDER_POS] = (sender_t){world, sizeof(world_t),
        sockfd, 0};
    senders[CUSTOM_SENDER_POS] = (sender_t){&pos, sizeof(clt_player_pos_t),
        sockfd, 1};
    return (send_player_position(convert_senders_to_data(senders)));
}

static void write_player_position(const srv_player_pos_t *pos, int sockfd)
{
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_POS_LEN;
    pkt_header_t hdr = {SRV_PLAYER_POSITION, PROTOCOL_VERSION,
        SRV_PLAYER_POS_LEN, 0};

    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, pos, SRV_PLAYER_POS_LEN);
    write(sockfd, to_write, size);
    free(to_write);
}

int send_player_position(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    world_t *world = 0x0;
    player_t *player = 0x0;
    clt_player_pos_t *clt = {0};
    srv_player_pos_t srv = {0};
    
    if (senders == 0x0)
        return (-1);
    world = (world_t*)(senders[WORLD_SENDER_POS].data);
    clt = (clt_player_pos_t*)(senders[CUSTOM_SENDER_POS].data);
    for (node_t *node = world->players.head ; node ; node = node->next) { 
        player = (player_t*)node->data;
        if (player->id == clt->player_num)
            break;
    }
    srv = (srv_player_pos_t){clt->player_num, player->x, player->y,
        player->orientation};
    write_player_position(&srv, senders[WORLD_SENDER_POS].sockfd);
    free(senders);
    return (SRV_PLAYER_POSITION);
}
