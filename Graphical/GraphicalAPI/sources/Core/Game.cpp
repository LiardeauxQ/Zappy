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
, tileTexture(new sf::Texture())
, resourceTexture(new sf::Texture())
{
    std::srand(std::time(nullptr));
    initialize();
}

void zapi::Game::initialize()
{
    tileTexture->loadFromFile("sprites/grass.png", sf::IntRect(0, 0, 100, 100));
    resourceTexture->loadFromFile("sprites/crystal.png", sf::IntRect(0, 0, 32, 64));
    tileTexture->setSmooth(true);
    resourceTexture->setSmooth(true);
    for (float i = 0, x = 0, y = 0; i != 900; i++, x += 100) {
        if (x >= 3000) {
            x = 0;
            y += 100;
            // y += 100 * std::sqrt(2);
        }
        tiles.push_back(Tile(tileTexture, resourceTexture, sf::Vector2f(100, 100), sf::Vector2f(x, y)));
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
    zapi::Tile *tile = findTile(position);
    for (auto &team : teams)
        if (team.getName() == teamName) {
            team.addPlayer(id, tile, position);
            return;
        }
    addTeam(teamName);
    addPlayer(teamName, id, position);
}

zapi::Tile *zapi::Game::findTile(const sf::Vector2f &position)
{
    for (int i = 0; i != tiles.size(); i++) {
        if (tiles[i].getPosition().x > position.x) {
            for (i--; i < tiles.size(); i += 30) {
                if (tiles[i].getPosition().y > position.y)
                    return &tiles[i--];
            }
        }
    }
    return (NULL);
}
