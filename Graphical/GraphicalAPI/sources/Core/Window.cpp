/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window implementation
*/

#include <iostream>
#include "Core/Window.hpp"

zapi::Window::Window(const std::string &title, unsigned int width, unsigned int height)
: sf::RenderWindow(sf::VideoMode::getDesktopMode(), title)
, hud()
, menu(*this)
, event()
, width(width)
, height(height)
, camera(sf::FloatRect(0, 0, 1920, 1080))
{
    setView(camera);
}

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

void zapi::Window::inputHandler(void)
{
    if (event.type == sf::Event::Closed)
        close();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        close();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
        camera.move(0, -40);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
        camera.move(0, 40);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
        camera.move(-40, 0);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
        camera.move(40, 0);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
        camera.zoom(0.99);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z) {
        camera.zoom(1.01);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
        hud.setEnd("The Winnerzz");
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

zapi::Menu &zapi::Window::getMenu()
{
    return menu;
}
