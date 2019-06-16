/*
** EPITECH PROJECT, 2019
** Tile.cpp
** File description:
** Tile implementation
*/

#include "Tile.hpp"

zapi::Tile::Tile(const sf::Vector2f &size, const sf::Vector2f &position)
: Entity(position)
, size(size)
, main(size)
{
    main.setFillColor(sf::Color::White);
    main.setOutlineColor(sf::Color::Red);
    main.setOutlineThickness(1);
    main.setPosition(position);
}

void zapi::Tile::update(sf::RenderWindow *window)
{
    window->draw(main);
}
