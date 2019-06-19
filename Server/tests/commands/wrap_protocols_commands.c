/*
** EPITECH PROJECT, 2018
** wrap_graph_protocol_commands.c
** File description:
** wrap protocol commands
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "world.h"
#include "graphical/protocols.h"
#include "graphical/commands.h"
#include "unit_tests.h"

void wrap_graph_protocol_commands(data_handler handler, int fd,
        const cmd_info_t *cmd)
{
    int magic_num = SENDER_MAGIC_NUM;
    char *data = calloc(1, SENDER_MAGIC_NUM_LEN);
    sender_t sender = {0};
    int is_last = 0;
    int offset = SENDER_MAGIC_NUM_LEN;

    memcpy(data, &magic_num, SENDER_MAGIC_NUM_LEN);
    for (size_t i = 0 ; cmd[i].data ; i++) {
        data = realloc(data, offset + sizeof(sender_t));
        if (cmd[i + 1].data == 0x0)
            is_last = 1;
        sender = (sender_t){cmd[i].data, cmd[i].size, fd, is_last};
        memcpy(data + offset, &sender, sizeof(sender_t));
        offset += sizeof(sender_t);
    }
    handler(data);
    lseek(fd, 0, SEEK_SET);
    free(data);
}
