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
    texture.loadFromFile("sprites/crystal.png", sf::IntRect(0, 0, 32, 64));
    texture.setSmooth(true);
    main.setFillColor(sf::Color::Yellow);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    main.setOutlineColor(sf::Color::Black);
    main.setOutlineThickness(1);
    main.setPosition(position);
}

void zapi::Resource::update(sf::RenderWindow *window)
{
    window->draw(sprite);
    window->draw(main);
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
