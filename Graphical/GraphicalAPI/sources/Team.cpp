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

void zapi::Team::addPlayer(int id, zapi::Tile *tile, const sf::Vector2f &position)
{
    players.push_back(Player(id, tile, position));
}

bool zapi::Team::checkPlayer(unsigned int id)
{
    for (auto &player : players) {
        if (player.getId() == id)
            return true;
    }
    return false;
}

zapi::Player &zapi::Team::getPlayer(unsigned int id)
{
    for (auto &player : players)
        if (player.getId() == id)
            return player;
}