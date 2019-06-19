/*
** EPITECH PROJECT, 2019
** Resource.cpp
** File description:
** Resource implementation
*/

#include "Resource.hpp"

zapi::Resource::Resource(const sf::Vector2f &size, const sf::Vector2f &position)
: Entity(position)
, quantity(0)
, size(size)
, main(size)
{
    // if (!texture.loadFromFile("../../sprites/crystal.png", sf::IntRect(position.x, position.y, 32, 64)))
    main.setFillColor(sf::Color::Yellow);
    // sprite.setTexture(texture);
    main.setOutlineColor(sf::Color::Black);
    main.setOutlineThickness(1);
    main.setPosition(position);
}

void zapi::Resource::update(sf::RenderWindow *window)
{
    //if (quantity < 0)
    window->draw(main);
    // window->draw(sprite);
}

zapi::Resource &zapi::Resource::operator++(int)
{
    quantity++;
    return *this;
}

zapi::Resource &zapi::Resource::operator--(int)
{
    if (quantity != 0)
        quantity--;
    return *this;
}
