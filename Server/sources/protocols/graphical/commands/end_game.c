/*
** EPITECH PROJECT, 2018
** handle_end_game.c
** File description:
** handle end game
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphical/protocols.h"
#include "graphical/commands.h"

int send_end_game(const void *data)
{
    sender_t *senders = get_senders_from_data(data);
    char *to_write = 0x0;
    size_t size = PKT_HDR_LEN + SRV_END_GAME_LEN;
    srv_end_game_t srv = {0};
    pkt_header_t hdr = {SRV_END_GAME, PROTOCOL_VERSION,
        SRV_END_GAME_LEN, 0};

    if (count_senders(senders) != 1)
        return (-1);
    if (senders[0].size != SHORT_MSG_LEN)
        return (-1);
    for (int i = 0 ; i < SHORT_MSG_LEN ; i++)
        srv.winning_team[i] = ((char*)senders[0].data)[i];
    to_write = calloc(1, size * sizeof(char));
    to_write = memcpy(to_write, &hdr, PKT_HDR_LEN);
    memcpy(to_write + PKT_HDR_LEN, &srv, SRV_END_GAME_LEN);
    write(senders[0].sockfd, to_write, size);
    free(senders);
    free(to_write);
    return (0);
}
