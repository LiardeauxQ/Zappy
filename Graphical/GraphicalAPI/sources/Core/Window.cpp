/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window implementation
*/

#include "Core/Window.hpp"

zapi::Window::Window(const std::string &title)
: sf::RenderWindow(sf::VideoMode::getDesktopMode(), title)
, entities()
{
}

void zapi::Window::addEntity(Entity *entity)
{
    entities.push_back(entity);
}

void zapi::Window::addEntity(Entity &entity)
{
    entities.push_back(&entity);
}

void zapi::Window::startLoop()
{
    loop();
}

void zapi::Window::loop()
{
    while (isOpen()) {
        eventHandler();
        clear();
        for (auto &entity : entities)
            entity->update(this);
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
