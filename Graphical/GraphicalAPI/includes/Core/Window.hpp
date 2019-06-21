/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window header
*/

#pragma once

#include "Tile.hpp"
#include "Team.hpp"
#include "Player.hpp"
#include <string>
#include <list>

namespace zapi
{
    class Window : public sf::RenderWindow {
        public:
            Window(const std::string &title);
            ~Window() = default;
            void update();
            void drawEntities(std::vector<Tile> &entities);
            void drawEntities(std::vector<Resource> &entities);
            void drawEntities(std::vector<Team> &entities);
            void drawEntities(std::list<Player> &entities);

        private:
            void inputHandler();
            sf::View camera;
            sf::View HUD;
            sf::Event event;
            int zoom;
    };
}
