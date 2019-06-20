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
, sprite()
{
    sprite.setTexture(*(getResourceTexture()));
    sprite.setPosition(position);
}

void zapi::Resource::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
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
