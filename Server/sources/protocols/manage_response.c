/*
** EPITECH PROJECT, 2018
** player_info_handlers.c
** File description:
** Handle every action on player informations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "manage_response.h"

static char *manage_response(int option, char *value)
{
    static char *response = 0x0;

    if (option)
        response = value;
    return (response);
}

char *get_response()
{
    return (manage_response(0, 0x0));
}

void set_response(char *value)
{
    manage_response(1, value);
}
