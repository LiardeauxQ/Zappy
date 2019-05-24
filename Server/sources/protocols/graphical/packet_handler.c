/*
** EPITECH PROJECT, 2018
** packet_handler.c
** File description:
** handle packet_handler struct
*/

#include "graphical/packets.h"

pkt_handler_t *init_pkt(int id, ...)
{
    pkt_handler_t *pkt = calloc(1, sizeof(pkt_handler_t));
    va_list ap;

    va_start(ap, id);
    pkt->id = id;
    pkt->subid = va_arg(ap, int);
    pkt->name = strdup(va_arg(ap, char *));
    pkt->handler = va_arg(ap, data_handler);
    va_end(ap);
    return (pkt);
}

void add_pkt_info(phr_t *reg, pkt_handler_t *handler)
{
    reg->size += 1;
    reg->handlers = realloc(reg->handlers, (reg->size + 1) * sizeof(pkt_handler_t*));
    if (reg->handlers == 0x0)
        exit_with_error("realloc");
    reg->handlers[reg->size - 1] = handler;
    reg->handlers[reg->size] = 0x0;
}
