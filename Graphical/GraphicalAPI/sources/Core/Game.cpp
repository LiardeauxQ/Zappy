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
    for (float i = 0, x = 0, y = 0; i != 900; i++, x += 102) {
        if (x >= 3000) {
            x = 0;
            y += 102;
        }
        tiles.push_back(Tile(sf::Vector2f(100, 100), sf::Vector2f(x, y)));
    }
    addPlayer("BP", 0, sf::Vector2f(0, 0));
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
        for (auto &team : teams)
            window.drawEntities(team.getPlayers());
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
            team.addPlayer(id, sf::Vector2f(50 - 28, 50 - 32));
            return;
        }
    addTeam(teamName);
    addPlayer(teamName, id, position);
}
