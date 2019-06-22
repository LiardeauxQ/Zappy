/*
** EPITECH PROJECT, 2019
** Team.cpp
** File description:
** Team implementation
*/

#include "Team.hpp"

zapi::Team::Team(const std::string &name)
: name(name)
, players()
{}

void zapi::Team::addPlayer(int id, const sf::Vector2f &position)
{
    players.push_back(Player(id, position));
}
