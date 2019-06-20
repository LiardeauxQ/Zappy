/*
** EPITECH PROJECT, 2018
** protocols.c
** File description:
** handle graphical protocol
*/

#include <stdlib.h>

#include "graphical/packets.h"

void init_packets(phr_t *reg)
{
    init_client_packets(reg);
    init_server_environnements_packets(reg);
    init_server_actions_packets1(reg);
    init_server_actions_packets2(reg);
    init_server_additionals_packets(reg);
}

void destroy_packets(phr_t *reg)
{
    for (size_t i = 0 ; i < reg->size ; i++) {
        free(reg->handlers[i]->name);
        free(reg->handlers[i]);
    }
}
