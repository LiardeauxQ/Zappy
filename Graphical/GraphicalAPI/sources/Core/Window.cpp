/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window implementation
*/

#include "Core/Window.hpp"

zapi::Window::Window(const std::string &title)
: sf::RenderWindow(sf::VideoMode::getDesktopMode(), title)
, camera(sf::FloatRect(700, 1100, 1600, 800))
, hud()
, event()
, zoom(5)
{
    setView(camera);
}

void zapi::Window::update(void)
{
    clear();
    inputHandler();
    updateHUD();
    setView(camera);
}

void zapi::Window::updateHUD(void)
{
    setView(getDefaultView());
    draw(hud);
}

void zapi::Window::drawEntities(std::vector<Tile> &entities)
{
    for (auto &entity : entities) {
        this->draw(entity);
        drawEntities(entity.getResources());
    }
}

void zapi::Window::drawEntities(std::vector<Resource> &entities)
{
    for (auto &entity : entities)
        this->draw(entity);
}

void zapi::Window::drawEntities(std::vector<Team> &entities)
{
    for (auto &entity : entities)
        drawEntities(entity.getPlayers());
}

void zapi::Window::drawEntities(std::list<Player> &entities)
{
    for (auto &entity : entities)
        this->draw(entity);
}

void zapi::Window::inputHandler()
{
    while (pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            camera.move(0, -40);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            camera.move(0, 40);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            camera.move(-40, 0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            camera.move(40, 0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A && zoom < 10) {
            camera.zoom(0.9);
            zoom++;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z && zoom > 0) {
            camera.zoom(1.2);
            zoom--;
        }
    }
}
