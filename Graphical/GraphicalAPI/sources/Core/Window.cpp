/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window implementation
*/

#include "Core/Window.hpp"
#include <cstdlib>

zapi::Window::Window(const std::string &title)
: sf::RenderWindow(sf::VideoMode::getDesktopMode(), title)
, camera(sf::FloatRect(700, 1100, 1600, 800))
, event()
, entities()
{
    setView(camera);
    std::srand(std::time(nullptr));
}

void zapi::Window::addEntities(std::vector<std::shared_ptr<Entity>> &entityList)
{
    for (auto &entity : entityList)
        entities.push_back(entity);
}

void zapi::Window::addEntity(std::shared_ptr<Entity> entity)
{
    entities.push_back(entity);
}

void zapi::Window::startLoop()
{
    loop();
}

void zapi::Window::loop()
{
    while (isOpen()) {
        clear();
        for (auto &entity : entities)
            entity->update(this);
        eventHandler();
        setView(camera);
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
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            camera.move(0, -20);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            camera.move(0, 20);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            camera.move(-20, 0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            camera.move(20, 0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
            camera.zoom(0.2);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)
            camera.zoom(-0.2);
    }
}
