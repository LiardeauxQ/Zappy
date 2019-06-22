/*
** EPITECH PROJECT, 2019
** Resource.cpp
** File description:
** Resource implementation
*/

#include "Resource.hpp"

zapi::Resource::Resource(unsigned int id, const sf::Vector2f &position, unsigned int quantity, bool isHud)
: Entity(position)
, quantity(quantity)
, sprite()
, HUD(isHud)
{
    sprite.setTexture(*(getResourceTexture()));
    sprite.setTextureRect(sf::IntRect(96 * id, 0, 96, 96));
    if (!HUD)
        sprite.setScale(sf::Vector2f(0.2, 0.2));
    else
        sprite.setScale(sf::Vector2f(0.8, 0.8));
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

zapi::Resource &zapi::Resource::operator=(int amount)
{
    if (amount >= 0)
        quantity = amount;
    return *this;
}

unsigned int zapi::Resource::getQuantity(void)
{
    return quantity;
}