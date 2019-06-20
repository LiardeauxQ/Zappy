/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window header
*/

#pragma once

#include "Tile.hpp"
#include "Player.hpp"
#include <string>
#include <vector>

namespace zapi
{
    class Window : public sf::RenderWindow {
        public:
            Window(const std::string &title);
            ~Window() = default;
            void update();
            void drawEntities(std::vector<Tile> &entities);
            void drawEntities(std::vector<Resource> &entities);
            void drawEntities(std::vector<Player> &entities);

        private:
            void inputHandler();
            sf::View camera;
            sf::Event event;
            int zoom;
    };
}
