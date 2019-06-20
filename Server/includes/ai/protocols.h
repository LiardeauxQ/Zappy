/*
** EPITECH PROJECT, 2018
** protocol.h
** File description:
** protocols for AI client
*/

#pragma once

#include <stdint.h>
#include <stdlib.h>

#pragma pack(1)

/*
** DANGLING_HANDLER -> Handler function is NULL
*/
enum HANDLING_ERRORS {
    NO_ERROR                = 0,
    INVALID_PARAMETERS      = 1,
    DANGLING_HANDLER        = 2
};

typedef int (*action_handler_fcnt)(const uint16_t limit_cycles, const char **args);

/*
** Handle each actions by representing and describing each ones.
** -> command - String received by the server. Determine the required action.
** -> limit_cycles - Limit of cycles per reciprocal of time unit.
**      Determine execution time limit with the following formula :
**      (limit_cycles / f) with f the reciprocal of time unit.
**      If limit_cycles == -1, no execution time limit.
** -> args_nbr - Number of mandatory arguments for the specified command.
** -> handler - Function pointer to the handler.
*/
struct action_handler {
    char *command;
    uint16_t limit_cycles;
    uint16_t args_nbr;
    action_handler_fcnt handler;
};

typedef struct action_handler act_handler_t;

/*
** Monolithic structure used to register action handlers.
** handlers must be NULL-terminated;
*/
struct action_handler_register {
    size_t size;
    act_handler_t **handlers;
};

typedef struct action_handler_register ahr_t;

#pragma options align=reset

