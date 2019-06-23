/*
** EPITECH PROJECT, 2018
** handle_player_connection.c
** File description:
** handle player connection
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

int assign_new_player_connection(player_t *player, team_t *teams, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};
    int size = 0;

    while (teams[size++].name);
    senders[PLAYER_SENDER_POS] = (sender_t){player, sizeof(player_t),
        sockfd, 0};
    senders[TEAMS_SENDER_POS] = (sender_t){teams, size * sizeof(team_t),
        sockfd, 0};
    senders[CUSTOM_SENDER_POS].is_last = 1;
    return (send_player_connection(convert_senders_to_data(senders)));

}

static srv_new_player_connect_t convert_player_to_srv(player_t *player,
        team_t *teams)
{
    srv_new_player_connect_t srv = {0};

    srv.player_num = player->id;
    srv.x = player->x;
    srv.y = player->y;
    srv.orientation = player->orientation;
    srv.level = player->level;
    for (int i = 0 ; teams[i].name ; i++) {
        if ((unsigned int)teams[i].id == player->team_id
                && strlen(teams[i].name) < SHORT_MSG_LEN) {
            strcpy(srv.team_name, teams[i].name);
            break;
        }
    }
    return (srv);
}

int send_player_connection(const void __attribute__((unused)) *data)
{
    sender_t *senders = get_senders_from_data(data);
    player_t *player = 0x0;
    team_t *teams = 0x0;
    srv_new_player_connect_t srv = {0};
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_NEW_PLAYER_CONNECT_LEN;
    pkt_header_t hdr = {SRV_NEW_PLAYER_CONNECT, PROTOCOL_VERSION,
        SRV_NEW_PLAYER_CONNECT_LEN, 0};

    if (senders == 0x0)
        return (-1);
    player = (player_t*)(senders[PLAYER_SENDER_POS].data);
    teams = (team_t*)(senders[TEAMS_SENDER_POS].data);
    srv = convert_player_to_srv(player, teams);
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_NEW_PLAYER_CONNECT_LEN);
    write(senders[PLAYER_SENDER_POS].sockfd, to_write, size);
    free(to_write);
    free(senders);
    return (SRV_NEW_PLAYER_CONNECT);
}
