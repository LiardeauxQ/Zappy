/*
** EPITECH PROJECT, 2018
** test_team_name.c
** File description:
** test team name
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "graphical/commands.h"
#include "graphical/protocols.h"
#include "world.h"
#include "linked_list.h"
#include "unit_tests.h"

Test(send_team_names, simple_test)
{
    int fd = open("tmp_team_name", O_CREAT | O_RDWR, 0644);
    char buffer[256] = {0};
    const size_t size = PKT_HDR_LEN + SRV_TEAMS_NAMES_LEN;
    char result[PKT_HDR_LEN + SRV_TEAMS_NAMES_LEN + 1] = {0};
    pkt_header_t hdr = {SRV_TEAMS_NAMES, PROTOCOL_VERSION,
        SRV_TEAMS_NAMES_LEN, 0};
    srv_teams_names_t srv = {"test"};
    char team[] = "test";
    cmd_info_t cmd[MAX_SENDERS] = {{0}};

    cmd[MSG_SENDER_POS] = (cmd_info_t){team, strlen(team)};
    cr_assert_neq(fd, -1);
    memcpy(result, &hdr, PKT_HDR_LEN);
    memcpy(result + PKT_HDR_LEN, &srv, SRV_TEAMS_NAMES_LEN);
    wrap_graph_protocol_commands(&send_name_teams, fd, cmd);
    read(fd, buffer, size);
    for (size_t i = 0 ; i < size ; i++)
        cr_assert_eq(buffer[i], result[i]);
    close(fd);
}
