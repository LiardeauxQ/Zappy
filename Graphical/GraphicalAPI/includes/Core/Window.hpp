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
#include <memory>

namespace zapi
{
    class Window : public sf::RenderWindow {
        public:
            Window(const std::string &title);
            ~Window() = default;
            void addEntities(std::vector<std::shared_ptr<Entity>> &entityList);
            void addEntity(std::shared_ptr<Entity> entity);
            void startLoop();
        private:
            void loop();
            void eventHandler();
            sf::View camera;
            sf::Event event;
            std::vector<std::shared_ptr<Entity>> entities;
    };
}
