/*
** EPITECH PROJECT, 2019
** Game.hpp
** File description:
** Game header
*/

#pragma once

#define MAX_PLAYERS 7

#include <cmath>
#include "Tile.hpp"
#include "Team.hpp"
#include "Window.hpp"

namespace zapi
{
    class Game {
        public:
            Game();
            ~Game() = default;
        protected:
            void initialize();
            void updateTile(sf::Vector2f &position, const std::vector<int> &res);
            void addTeam(const std::string &teamName); //TODO: check if team exist
            void addPlayer(const std::string &teamName, int id, const sf::Vector2f &position);
            void removePlayer(unsigned int id);
            Tile *findTile(const sf::Vector2f &position);
            void movePlayer(unsigned int id, ORIENTATION direction);
            void dropResourcePlayer(unsigned int id, RESOURCE_NUMBER index);
            void pickUpResourcePlayer(unsigned int id, RESOURCE_NUMBER index);
            void updatePlayerOrientation(unsigned int id, ORIENTATION direction);
            void levelUpPlayer(unsigned int id);
            zapi::Player &getPlayer(unsigned int id);

            void updatePlayer(unsigned int id, const sf::Vector2f &position, ORIENTATION direction);
            void updatePlayer(unsigned int id, const sf::Vector2f &position,
                    std::array<int, MAX_PLAYERS> &resources);
            void expulsePlayer(unsigned int id);
            void startIncantation(unsigned int sender, const sf::Vector2f &position,
                    std::array<int, MAX_PLAYERS> &players);
            void stopIncantation(RESULT result, const sf::Vector2f &position);
            void broadcast(unsigned int sender, const std::string &message);
            void eggLaying(unsigned int id);
            void eggLayed(unsigned int sender, unsigned int id, const sf::Vector2f &position);
            void eggHatching(unsigned int id);
            void eggHatched(unsigned int id);
            void eggHatchedDeath(unsigned int id);
            void endGame(const std::string &teamName);

            bool checkInsideGrid(sf::Vector2f const &coord);

            std::vector<Tile> &getTiles(void) { return tiles; }
            std::vector<Team> &getTeams(void) { return teams; }
        private:
            std::vector<Tile> tiles;
            std::vector<Team> teams;
    };
}
