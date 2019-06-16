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

    main.setFillColor(sf::Color::Yellow);
    main.setOutlineColor(sf::Color::Black);
    main.setOutlineThickness(1);
    main.setPosition(position);
}

void zapi::Resource::update(sf::RenderWindow *window)
{
    //if (quantity < 0)
    window->draw(main);
}
