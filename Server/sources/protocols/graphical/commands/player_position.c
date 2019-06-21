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
    size_t size = count_senders(senders);
    world_t *world = 0x0;
    player_t *player = 0x0;
    clt_player_pos_t *clt = {0};
    srv_player_pos_t srv = {0};
    
    if (size != 2)
        return (-1);
    world = (world_t*)(senders[0].data);
    clt = (clt_player_pos_t*)(senders[1].data);
    for (node_t *node = world->players.head ; node ; node = node->next) { 
        player = (player_t*)node->data;
        if (player->id == clt->player_num)
            break;
    }
    srv = (srv_player_pos_t){clt->player_num, player->x, player->y,
        player->direction};
    write_player_position(&srv, senders[0].sockfd);
    free(senders);
    return (0);
}
