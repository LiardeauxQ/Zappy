/*
** EPITECH PROJECT, 2019
** Tile.cpp
** File description:
** Tile implementation
*/

#include <cstdlib>
#include "Tile.hpp"

zapi::Tile::Tile(const sf::Vector2f &size, const sf::Vector2f &position)
    : Entity(position), size(size), main(size), resources()
{
    texture.loadFromFile("sprites/grass.png", sf::IntRect(0, 0, 100, 100));
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    // main.setOutlineColor(sf::Color::Black);
    // main.setOutlineThickness(1);
    // main.setPosition(position);

    for (int i = 0; i != 7; i++)
        resources.push_back(Resource(sf::Vector2f(size.x/8, size.y/8), position + sf::Vector2f((std::rand()%((int)size.x - (int)size.x/8)), (std::rand()%((int)size.y - (int)size.y/8)))));
}

void zapi::Tile::update(sf::RenderWindow *window)
{
    // window->draw(main);
    window->draw(sprite);
}
