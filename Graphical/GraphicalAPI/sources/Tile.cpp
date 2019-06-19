/*
** EPITECH PROJECT, 2019
** Tile.cpp
** File description:
** Tile implementation
*/

#include "Tile.hpp"
#include <cstdlib>

zapi::Tile::Tile(const sf::Vector2f &size, const sf::Vector2f &position)
    : Entity(position), size(size), main(size), resources()
{
    // if (!texture.loadFromFile("sprites/grass.png", sf::IntRect(position.x, position.y, 100, 100)))
        main.setFillColor(sf::Color::White);
    // else
        // sprite.setTexture(texture);
    main.setOutlineColor(sf::Color::Red);
    main.setOutlineThickness(1);
    // main.setRotation(45);
    // main.rotate(45);
    main.setPosition(position);

    for (int i = 0; i != 7; i++)
        resources.push_back(std::make_shared<Resource>(Resource(sf::Vector2f(size.x / 8, size.y / 8), position + sf::Vector2f((std::rand() % ((int)size.x - (int)size.x / 8)), (std::rand() % ((int)size.y - (int)size.y / 8))))));
}

void zapi::Tile::update(sf::RenderWindow *window)
{
    window->draw(main);
    // window->draw(sprite);
    for (auto &resource : resources)
        resource->update(window);
}
