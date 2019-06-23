/*
** EPITECH PROJECT, 2018
** protocol.h
** File description:
** Protocols for AI client
*/

#pragma once
 
#define _GNU_SOURCE

#include <stdint.h>
#include <stdlib.h>

#define WELCOME_MSG "WELCOME\n"
#define WELCOME_MSG_LEN 8

#include "player.h"

#ifdef __clang__
#   pragma pack(1)
#endif /* __clang__ */

#if defined (__GNUC__) && (__GNUC__ >= 7)
#   define PACKED __attribute__((packed))
#else
#   define PACKED
#endif

/*
** Return an error flag in case of error (HANDLING_ERRORS).
*/
typedef int (*action_handler_fcnt)(world_t *world, player_t *player,
        const char **args);

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
    uint16_t limit_cycles;
    uint16_t args_nbr;
    char *command;
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

#ifdef __clang__
#   pragma options align=reset
#endif /* __clang__ */

