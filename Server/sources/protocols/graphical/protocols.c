/*
** EPITECH PROJECT, 2018
** protocols.c
** File description:
** handle graphical protocol
*/

#include "graphical/packets.h"

void init_packets(phr_t *reg)
{
    init_client_packets(reg);
    init_server_environnements_packets(reg);
    init_server_actions_packets(reg);
    init_server_additionals_packets(reg);
}
