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
#include "Core/Hud.hpp"
#include "Core/Menu.hpp"
#include <string>
#include <list>

namespace zapi
{
    class Window : public sf::RenderWindow {
        public:
            Window(const std::string &title, unsigned int width, unsigned int height);
            ~Window() = default;
            // void update(void);
            void updateHUD(void);
            void drawEntities(std::vector<Tile> &entities);
            void drawEntities(std::vector<Resource> &entities);
            void drawEntities(std::list<Player> &entities, sf::Time frameTime);
            sf::View &getCamera(void);
            Hud &getHUD(void);
            sf::Event &getEvent(void);
            void inputHandler(void);
            Menu &getMenu(void);

        private:
            Hud hud;
            Menu menu;
            sf::Event event;
            unsigned int __attribute__((unused)) width;
            unsigned int __attribute__((unused)) height;
            sf::View camera;
    };
}
