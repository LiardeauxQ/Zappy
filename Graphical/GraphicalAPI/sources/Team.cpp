/*
** EPITECH PROJECT, 2019
** Team.cpp
** File description:
** Team implementation
*/

#include "Team.hpp"

zapi::Team::Team()
: players()
{}

void zapi::Team::addPlayer(Player *player)
{
    players.push_back(player);
}

void zapi::Team::addPlayer(Player &player)
{
    players.push_back(&player);
}
