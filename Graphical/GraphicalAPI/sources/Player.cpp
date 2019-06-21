/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player implementation
*/

#include "Player.hpp"

zapi::Player::Player(unsigned int id, const sf::Vector2f &position)
: Entity(position)
, id(id)
, sprite()
, inventory()
{

    sprite.setTexture(*(getPlayerTexture()));
    sprite.setTextureRect(sf::IntRect(385, 388, 55, 64));
    sprite.setPosition(position);
}

void zapi::Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite);
}

void zapi::Player::move(ORIENTATION direction)
{
    if (direction == NORTH) {
        sprite.move(0, -100);
    }
    if (direction == EAST) {
        sprite.move(100, 0);
    }
    if (direction == WEST) {
        sprite.move(-100, 0);
    }
    if (direction == SOUTH) {
        sprite.move(0, 100);
    }
}
