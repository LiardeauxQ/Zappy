/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window header
*/

#pragma once

#include "Utils.hpp"
#include <string>

namespace zapi
{
    class Window : public sf::RenderWindow {
        public:
            Window(const std::string &title);
            ~Window() = default;
        private:
            void loop();
            void eventHandler();
            sf::Event event;
    };
}
