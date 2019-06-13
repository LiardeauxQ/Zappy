/*
** EPITECH PROJECT, 2018
** player.h
** File description:
** Player header
*/

#pragma once

#include <stdint.h>

/*
** Each directions are associated to an int.
*/
enum DIRECTION {
    UP      = 0,
    RIGHT   = 1,
    DOWN    = 2,
    LEFT    = 3
};

/*
** Each ressources are associated to a specific ID.
*/
enum RESOURCE_ID {
    LINEMATE    = 0,
    DERAUMERE   = 1,
    SIBUR       = 2,
    MENDIANE    = 3,
    PHIRAS      = 4,
    THYSTAME    = 5
};

/*
** Abstraction of 2D coordinates on the map.
*/
struct coordinates {
    unsigned int x;
    unsigned int y;
};

typedef struct coordinates coordinates_t;

/*
** Caracteritics of a player.
*/
struct player {
    uint8_t level;
    unsigned int hp;
    unsigned int f;
    enum DIRECTION direction;
    unsigned int resources[7];
    coordinates_t position;
};

typedef struct player player_t;
