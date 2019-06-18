/*
** EPITECH PROJECT, 2019
** Game.hpp
** File description:
** Game header
*/

#pragma once

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
            void addTeam(const std::string &teamName);
            void addPlayer(const std::string &teamName, int id, const sf::Vector2f &position);
        private:
            Window window;
            std::vector<std::shared_ptr<Entity>> tiles;
            std::vector<Team> teams;
    };
}
