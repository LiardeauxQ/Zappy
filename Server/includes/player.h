/*
** EPITECH PROJECT, 2018
** player.h
** File description:
** player header
*/

/**
 * \file player.h
 * \brief player functions.
 * \date Jun, 23 2019
 *
 */

#pragma once

#include "world.h"
#include "resources.h"
#include "graphical/protocols.h"

/* create_player.c */

int add_player(world_t *world, const unsigned int team_id); // return player_id

/* destroy_player.c */

int remove_player(world_t *world, player_t *player);
