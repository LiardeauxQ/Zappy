/*
** EPITECH PROJECT, 2018
** handle_name_teams.c
** File description:
** handle teams's name
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

void *assign_team_name(char *team, int sockfd)
{
    sender_t senders[MAX_SENDERS] = {{0}};

    senders[MSG_SENDER_POS] = (sender_t){team, strlen(team), sockfd, 0};
    senders[CUSTOM_SENDER_POS].is_last = 1;
    return (convert_senders_to_data(senders));
}

int get_name_teams(const void __attribute__((unused)) *data)
{
    return (0);
}

int send_name_teams(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    srv_teams_names_t srv = {0};
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_TEAMS_NAMES_LEN;
    pkt_header_t hdr = {SRV_TEAMS_NAMES, PROTOCOL_VERSION,
        SRV_TEAMS_NAMES_LEN, 0};

    if (senders == 0x0)
        return (-1);
    strcpy(srv.team_name, (char*)(senders[MSG_SENDER_POS].data));
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_TEAMS_NAMES_LEN);
    write(senders[MSG_SENDER_POS].sockfd, to_write, size);
    free(to_write);
    free(senders);
    return (SRV_TEAMS_NAMES);
}
