/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window implementation
*/

#include <iostream>
#include "Core/Window.hpp"

zapi::Window::Window(const std::string &title)
: sf::RenderWindow(sf::VideoMode::getDesktopMode(), title)
, camera(sf::FloatRect(700, 1100, 1600, 900))
, hud()
, event()
, zoom(5)
{
    setView(camera);
}

// void zapi::Window::update(void)
// {
//     // clear();
//     // inputHandler();
//     // setView(camera);
// }

void zapi::Window::updateHUD(void)
{
    setView(getDefaultView());
    hud.updateResourceOutputs();
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

void zapi::Window::drawEntities(std::list<Player> &entities, sf::Time frameTime)
{
    for (auto &entity : entities) {
        if (!entity.update(frameTime)) {
            entity.currentAnimation = entity.getPlayerAnimation((PLAYER_ANIMATION)entity.getOrientation());
            entity.currentAnimation->play();
        }
        this->draw(*entity.currentAnimation);
    }
}

void zapi::Window::inputHandler()
{
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

sf::View &zapi::Window::getCamera(void)
{
    return camera;
}

zapi::Hud &zapi::Window::getHUD(void)
{
    return hud;
}

sf::Event &zapi::Window::getEvent(void)
{
    return event;
}
