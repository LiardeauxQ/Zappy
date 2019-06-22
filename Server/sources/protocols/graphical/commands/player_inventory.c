/*
** EPITECH PROJECT, 2018
** handle_player_inventory.c
** File description:
** handle player's inventory
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"


int get_player_inventory(const void __attribute__((unused)) *data)
{
    return (0);
}

static srv_player_inventory_t fill_srv_player_inventory(player_t *player)
{
    srv_player_inventory_t inv = {0};

    inv.player_num = player->id;
    inv.x = player->x;
    inv.y = player->y;
    inv.q0 = player->resources[0];
    inv.q1 = player->resources[1];
    inv.q2 = player->resources[2];
    inv.q3 = player->resources[3];
    inv.q4 = player->resources[4];
    inv.q5 = player->resources[5];
    inv.q6 = player->resources[6];
    return (inv);
}

static void write_player_inventory(const srv_player_inventory_t *inv,
        int sockfd)
{
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_PLAYER_INVENTORY_LEN;
    pkt_header_t hdr = {SRV_PLAYER_INVENTORY, PROTOCOL_VERSION,
        SRV_PLAYER_INVENTORY_LEN, 0};

    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, inv, SRV_PLAYER_INVENTORY_LEN);
    write(sockfd, to_write, size);
    free(to_write);
}

int assign_player_inventory(world_t *world,
        struct clt_player_inventory *clt, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[WORLD_SENDER_POS] = (sender_t){world, sizeof(world_t),
        sockfd, 0};
    senders[CUSTOM_SENDER_POS] = (sender_t){clt,
        sizeof(struct clt_player_inventory), sockfd, 1};
    return (send_player_inventory(convert_senders_to_data(senders)));
}

int send_player_inventory(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    world_t *world = 0x0;
    player_t *player = 0x0;
    struct clt_player_inventory *clt = {0};
    srv_player_inventory_t srv = {0};
    
    if (senders == 0x0)
        return (-1);
    world = (world_t*)(senders[WORLD_SENDER_POS].data);
    clt = (struct clt_player_inventory*)(senders[CUSTOM_SENDER_POS].data);
    for (node_t *node = world->players.head ; node ; node = node->next) { 
        player = (player_t*)node->data;
        if (player->id == clt->player_num)
            break;
    }
    srv = fill_srv_player_inventory(player);
    write_player_inventory(&srv, senders[WORLD_SENDER_POS].sockfd);
    free(senders);
    return (SRV_PLAYER_INVENTORY);
}
