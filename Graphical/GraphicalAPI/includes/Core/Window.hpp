/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window header
*/

#ifndef WINDOW_HPP
	#define WINDOW_HPP

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
            void eventDisplay();
            sf::Event event;
    };
}

#endif /* !WINDOW_HPP */
