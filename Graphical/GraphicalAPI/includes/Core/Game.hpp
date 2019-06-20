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
            void addTeam(const std::string &teamName);
            void addPlayer(const std::string &teamName, int id, const sf::Vector2f &position);
        private:
            Window window;
            std::vector<Tile> tiles;
            std::vector<Team> teams;
    };
}
