/*
** EPITECH PROJECT, 2019
** Game.cpp
** File description:
** Game implementation
*/

#include "Core/Game.hpp"
#include <cstdlib>

zapi::Game::Game(const std::string &title)
: window(title)
, tiles()
, teams()
{
    std::srand(std::time(nullptr));
    initialize();
}

void zapi::Game::initialize()
{
    for (float i = 0, x = 0, y = 0; i != 900; i++, x += 100) {
        if (x >= 3000) {
            x = 0;
            y += 100;
            // y += 100 * std::sqrt(2);
        }
        tiles.push_back(Tile(sf::Vector2f(100, 100), sf::Vector2f(x, y)));
    }
}

void zapi::Game::start()
{
    loop();
}

void zapi::Game::loop()
{
    while (window.isOpen()) {
        window.update();
        window.drawEntities(tiles);
        window.display();
    }
}

void zapi::Game::addTeam(const std::string &teamName)
{
    teams.push_back(Team(teamName));
}

void zapi::Game::addPlayer(const std::string &teamName, int id, const sf::Vector2f &position)
{
    for (auto &team : teams)
        if (team.getName() == teamName) {
            team.addPlayer(id, position);
            return;
        }
    addTeam(teamName);
    addPlayer(teamName, id, position);
}
