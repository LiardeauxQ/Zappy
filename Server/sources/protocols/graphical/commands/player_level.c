/*
** EPITECH PROJECT, 2018
** handle_player_level.c
** File description:
** handle player's level
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

int get_player_level(const void __attribute__((unused)) *data)
{
    return (0);
}

static void write_player_level(const srv_player_level_t *lvl, int sockfd)
{
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_LEVEL_LEN;
    pkt_header_t hdr = {SRV_PLAYER_LEVEL, PROTOCOL_VERSION,
        SRV_PLAYER_LEVEL_LEN, 0};

    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &lvl, SRV_PLAYER_LEVEL_LEN);
    write(sockfd, to_write, size);
}

int send_player_level(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    size_t size = count_senders(senders);
    world_t *world = 0x0;
    player_t *player = 0x0;
    clt_player_level_t *clt = {0};
    srv_player_level_t srv = {0};
    
    if (size != 2)
        return (-1);
    world = (world_t*)(senders[0].data);
    clt = (clt_player_level_t*)(senders[1].data);
    for (node_t *node = world->players.head ; node ; node = node->next) { 
        player = (player_t*)node->data;
        if (player->id == clt->player_num)
            break;
    }
    srv = (srv_player_level_t){clt->player_num, player->level};
    write_player_level(&srv, senders[0].sockfd);
    free(senders);
    return (0);
}
