/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window implementation
*/

#include "Core/Window.hpp"

zapi::Window::Window(const std::string &title)
: sf::RenderWindow(sf::VideoMode::getDesktopMode(), title)
{
    loop();
}

void zapi::Window::loop()
{
    while (isOpen()) {
        eventHandler();
        clear();
        display();
    }
}

void zapi::Window::eventHandler()
{
    while (pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            close();
    }
}
