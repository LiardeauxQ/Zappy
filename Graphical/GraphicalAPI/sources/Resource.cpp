/*
** EPITECH PROJECT, 2019
** Resource.cpp
** File description:
** Resource implementation
*/

#include "Resource.hpp"

zapi::Resource::Resource(unsigned int id, const sf::Vector2f &position,
        unsigned int quantity)
: Entity(position)
, quantity(quantity)
, sprite()
{
    sprite.setTexture(*(getResourceTexture()));
    sprite.setTextureRect(sf::IntRect(96 * id, 0, 96, 96));
    sprite.setScale(sf::Vector2f(0.2, 0.2));
    sprite.setPosition(position);
}

void zapi::Resource::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (quantity)
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
