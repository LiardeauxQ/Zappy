/*
** EPITECH PROJECT, 2019
** Team.cpp
** File description:
** Team implementation
*/

#include "Team.hpp"

zapi::Team::Team(unsigned int width, unsigned int height, const std::string &name)
: name(name)
, players()
, width(width)
, height(height)
{}

void zapi::Team::addPlayer(int id, zapi::Tile *tile, const sf::Vector2f &position)
{
    players.push_back(Player(id, tile, width, height, position));
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
    return players.front();
}

void zapi::Team::removePlayer(unsigned int id)
{
    players.remove_if([id](zapi::Player p){ return p.getId() == id; });
}

void zapi::Team::updatePlayerOrientation(unsigned int id, ORIENTATION direction)
{
    for (auto &player : players) {
        if (player.getId() == id) {
            player.updateOrientation(direction);
            return;
        }
    }
}
