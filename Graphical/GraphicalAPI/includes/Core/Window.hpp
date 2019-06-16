/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window header
*/

#pragma once

#include "Entity.hpp"
#include <string>
#include <vector>

namespace zapi
{
    class Window : public sf::RenderWindow {
        public:
            Window(const std::string &title);
            ~Window() = default;
            void addEntity(Entity *entity);
            void addEntity(Entity &entity);
            void startLoop();
            sf::View camera;
        private:
            void loop();
            void eventHandler();
            sf::Event event;
            std::vector<Entity *> entities;
    };
}
