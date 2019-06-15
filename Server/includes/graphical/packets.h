/*
** EPITECH PROJECT, 2018
** packets.h
** File description:
** packets header
*/

#pragma once

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "protocols.h"
#include "error.h"

/* packet_handler.c */

pkt_handler_t *init_pkt(int id, ...);
phr_t *add_pkt_info(phr_t *reg, pkt_handler_t *handler);

/* init_packets.c */

int init_client_packets(phr_t *reg);
int init_server_environnements_packets(phr_t *reg);
int init_server_actions_packets(phr_t *reg);
int init_server_additionals_packets(phr_t *reg);