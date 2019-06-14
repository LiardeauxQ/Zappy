/*
** EPITECH PROJECT, 2018
** init_action_handlers.c
** File description:
** Initialize every actions handler and store these in a registrar
*/

#include "ai/init_action_handlers.h"

act_handler_t *init_action_handler(char *command, uint16_t limit_cycles,
    uint16_t args_nbr, action_handler_fcnt handler)
{
    act_handler_t *action = malloc(sizeof(act_handler_t));

    if (!action) {
        exit_with_error("malloc");
    }
    action->command = command;
    action->limit_cycles = limit_cycles;
    action->args_nbr = args_nbr;
    action->handler = handler;
    return (action);
}

void register_action_handler(ahr_t *registrar, act_handler_t *handler)
{
    registrar->size += 1;
    registrar->handlers = realloc(registrar->handlers,
            (registrar->size + 1) * sizeof(act_handler_t *));
    if (registrar->handlers == 0x0) {
        exit_with_error("realloc");
    }
    registrar->handlers[registrar->size - 1] = handler;
    registrar->handlers[registrar->size] = 0x0;
}

void init_action_handler_register(ahr_t *reg)
{
    register_action_handler(reg, init_action_handler("Forward", 7, 0, 0x0));
    register_action_handler(reg, init_action_handler("Right", 7, 0, 0x0));
    register_action_handler(reg, init_action_handler("Left", 7, 0, 0x0));
    register_action_handler(reg, init_action_handler("Look", 7, 0, 0x0));
    register_action_handler(reg, init_action_handler("Inventory", 1, 0, 0x0));
    register_action_handler(reg, init_action_handler("Broadcast", 7, 1, 0x0));
    register_action_handler(reg,
            init_action_handler("Connect_nbr", -1, 0, 0x0));
    register_action_handler(reg, init_action_handler("Fork", 42, 0, 0x0));
    register_action_handler(reg, init_action_handler("Eject", 7, 0, 0x0));
    register_action_handler(reg, init_action_handler("", -1, 0, 0x0));
    register_action_handler(reg, init_action_handler("Take", 7, 1, 0x0));
    register_action_handler(reg, init_action_handler("Set", 7, 1, 0x0));
    register_action_handler(reg,
            init_action_handler("Incantation", 300, 0, 0x0));
}
