/*
** EPITECH PROJECT, 2019
** Game.hpp
** File description:
** Game header
*/

#pragma once

#include <cmath>
#include "Window.hpp"
#include "Tile.hpp"
#include "Team.hpp"

namespace zapi
{
    class Game {
        public:
            Game(const std::string &title);
            ~Game() = default;
            void initialize();
            void start();
            void loop();
            void updateTile(sf::Vector2f vector, std::vector<zapi::Resource> &res);
            void addTeam(const std::string &teamName);
            void addPlayer(const std::string &teamName, int id, const sf::Vector2f &position);
            void removePlayer(unsigned int id);
            Tile *findTile(const sf::Vector2f &position);
            void movePlayer(unsigned int id, ORIENTATION direction);
            void dropResourcePlayer(unsigned int id, RESOURCE_NUMBER index);
            void pickUpResourcePlayer(unsigned int id, RESOURCE_NUMBER index);
            void updatePlayerOrientation(unsigned int id, ORIENTATION direction);
            void levelUpPlayer(unsigned int id);
            zapi::Player getPlayer(unsigned int id);

            void updatePlayer(unsigned int id, const sf::Vector2f &position, ORIENTATION direction);
            void updatePlayer(unsigned int id, const sf::Vector2f &position, std::array<int, 7> &resources);
            void expulsePlayer(unsigned int id);
            void startIncantation(unsigned int sender, const sf::Vector2f &position, std::array<int, 7> &players);
            void stopIncantation(RESULT result, const sf::Vector2f &position);
            void broadcast(unsigned int sender, const std::string &message);
            void eggLaying(unsigned int id);
            void eggLayed(unsigned int sender, unsigned int id, const sf::Vector2f &position);
            void eggHatching(unsigned int id);
            void eggHatched(unsigned int id);
            void eggHatchedDeath(unsigned int id);
            void endGame(const std::string &teamName);

        private:
            Window window;
            std::vector<Tile> tiles;
            std::vector<Team> teams;
    };
}
