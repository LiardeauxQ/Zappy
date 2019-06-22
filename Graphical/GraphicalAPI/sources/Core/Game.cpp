/*
** EPITECH PROJECT, 2019
** Game.cpp
** File description:
** Game implementation
*/

#include "Core/Game.hpp"
#include <cstdlib>
#include <iostream>

zapi::Game::Game() : tiles(), teams()
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
        }
        tiles.push_back(Tile(sf::Vector2f(100, 100), sf::Vector2f(x, y)));
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
            zapi::Tile *tile = findTile(position);
            team.addPlayer(id, tile, position + sf::Vector2f(50 - 32, 50 - 32));
            return;
        }
    addTeam(teamName);
    addPlayer(teamName, id, position);
}

zapi::Tile *zapi::Game::findTile(const sf::Vector2f &position)
{
    unsigned int index = ((int)position.x / 100) + (((int)position.y / 100) * 30);
    return &tiles[index];
}

void zapi::Game::movePlayer(unsigned int id, ORIENTATION direction)
{
    for (auto &team : teams) {
        if (team.checkPlayer(id)) {
            team.getPlayer(id).move(direction);
            team.getPlayer(id).resetTile(findTile(team.getPlayer(id).getPosition()));
            return;
        }
    }
}

void zapi::Game::dropResourcePlayer(unsigned int id, RESOURCE_NUMBER index)
{
    for (auto &team : teams) {
        if (team.checkPlayer(id)) {
            auto player = team.getPlayer(id);
            player.dropResource(index);
            return;
        }
    }
    std::cout << "Player " << id << " droped something" << std::endl;
}

void zapi::Game::pickUpResourcePlayer(unsigned int id, RESOURCE_NUMBER index)
{
    for (auto &team : teams) {
        if (team.checkPlayer(id)) {
            auto player = team.getPlayer(id);
            player.pickUpResource(index);
        }
    }
    std::cout << "Player " << id << " picked up something" << std::endl;
}

void zapi::Game::updateTile(sf::Vector2f &position, const std::vector<int> &res)
{
    for (unsigned int i = 0; i < tiles.size(); i++) {
        if (tiles[i].getPosition() == position) {
            tiles[i].updateResource(res);
            return;
        }
    }
}

void zapi::Game::removePlayer(unsigned int id)
{
    for (auto &team : teams) {
        if (team.checkPlayer(id)) {
            team.removePlayer(id);
            return;
        }
    }
    std::cout << "Player " << id << " die" << std::endl;
}

void zapi::Game::updatePlayerOrientation(unsigned int id, ORIENTATION direction)
{
    for (auto &team : teams) {
        if (team.checkPlayer(id)) {
            team.updatePlayerOrientation(id, direction);
            return;
        }
    }
}

void zapi::Game::levelUpPlayer(unsigned int id)
{
    for (auto &team : teams) {
        if (team.checkPlayer(id)) {
            auto player = team.getPlayer(id);
            player.levelUp();
            return;
        }
    }
    std::cout << "Player " << id << " leveled up" << std::endl;
}

zapi::Player zapi::Game::getPlayer(unsigned int id)
{
    for (auto &team : teams)
        if (team.checkPlayer(id))
            return team.getPlayer(id);
    return Player(-1, nullptr);
}

// void zapi::Game::inputHandler(void)
// {
//     window.clear();
//     while(window.pollEvent(window.getEvent())) {
//         window.inputHandler();
//         if (window.getEvent().type == sf::Event::MouseButtonPressed && window.getEvent().mouseButton.button == sf::Mouse::Left)
//             updateHud();
//     }
//     window.setView(window.getCamera());
// }

// void zapi::Game::updateHud(void)
// {
//      sf::Vector2f worldCoord = window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getCamera());

//     if (checkInsideGrid(worldCoord)) {
//         window.getHUD().updateTilePtr(findTile(worldCoord));
//         window.getHUD().switchDrawable();
//     }
// }

bool zapi::Game::checkInsideGrid(sf::Vector2f const &coord)
{
    return (coord.x < 0 || coord.x > 3000 || coord.y < 0 || coord.y > 3000) ? false : true;
}



void zapi::Game::updatePlayer(unsigned int id, const sf::Vector2f &position, ORIENTATION direction)
{
    std::cout << "Player " << id << " position updated" << std::endl;
}

void zapi::Game::updatePlayer(unsigned int id, const sf::Vector2f &position, std::array<int, 7> &resources)
{
    std::cout << "Player " << id << " inventory updated" << std::endl;
}

void zapi::Game::expulsePlayer(unsigned int id)
{
    std::cout << "Player " << id << " expulsed" << std::endl;
}

void zapi::Game::startIncantation(unsigned int sender, const sf::Vector2f &position, std::array<int, 7> &players)
{
    std::cout << "Player " << sender << " start incantation at [" << position.x << ", " << position.y << "]" << std::endl;
}

void zapi::Game::stopIncantation(RESULT result, const sf::Vector2f &position)
{
    std::cout << "Incantation stop at [" << position.x << ", " << position.y << "]" << std::endl;
}

void zapi::Game::broadcast(unsigned int sender, const std::string &message)
{
    std::cout << "Player " << sender << " sayed: \'" << message << "\'" << std::endl;
}

void zapi::Game::eggLaying(unsigned int id)
{
    std::cout << "egg " << id << "is laying" << std::endl;
}

void zapi::Game::eggLayed(unsigned int sender, unsigned int id, const sf::Vector2f &position)
{
    std::cout << "egg " << id << "layed by player" << id << "at [" << position.x << ", " << position.y << "]" << std::endl;
}

void zapi::Game::eggHatching(unsigned int id)
{
    std::cout << "egg " << id << "is hatching" << std::endl;
}

void zapi::Game::eggHatched(unsigned int id)
{
    std::cout << "egg " << id << " hatched " << std::endl;
}

void zapi::Game::eggHatchedDeath(unsigned int id)
{
    std::cout << "egg " << id << " Hatched Death ?" << std::endl;
}

void zapi::Game::endGame(const std::string &teamName)
{
    std::cout << teamName << " beat the game" << std::endl;
}
