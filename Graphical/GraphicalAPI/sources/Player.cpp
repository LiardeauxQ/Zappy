/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player implementation
*/

#include "Player.hpp"

zapi::Player::Player(unsigned int id, zapi::Tile *tile, const sf::Vector2f &position)
: Entity(position)
, orientation(SOUTH)
, level(0)
, id(id)
, sprite()
, tile(tile)
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
    switch (direction) {
        case NORTH:
            if (position.y - 100 > 0)
                sprite.setPosition(sf::Vector2f(position.x, position.y - 100));
            else
                sprite.setPosition(sf::Vector2f(position.x, 3000 - (50)));
            orientation = NORTH;
            break;
        case EAST:
            if (position.x + 100 < 3000)
                sprite.setPosition(sf::Vector2f(position.x + 100, position.y));
            else
                sprite.setPosition(sf::Vector2f(0 + (50), position.y));
            orientation = EAST;
            break;
        case WEST:
            if (position.x - 100 > 0)
                sprite.setPosition(sf::Vector2f(position.x - 100, position.y));
            else
                sprite.setPosition(sf::Vector2f(3000 - (50), position.y));
            orientation = WEST;
            break;
        case SOUTH:
            if (position.y + 100 < 3000)
                sprite.setPosition(sf::Vector2f(position.x, position.y + 100));
            else
                sprite.setPosition(sf::Vector2f(position.x, 0 + (50)));
            orientation = SOUTH;
            break;
    }
}

void zapi::Player::addInventory(RESOURCE_NUMBER index)
{
    inventory[index] += 1;
}

void zapi::Player::removeInventory(RESOURCE_NUMBER index)
{
    if (inventory[index] > 0)
        inventory[index] -= 1;
}

void zapi::Player::resetTile(zapi::Tile *tile)
{
    this->tile = tile;
}

void zapi::Player::levelUp(void)
{
    level++;
}

void zapi::Player::dropResource(RESOURCE_NUMBER index)
{
    tile->addResource(index);
    removeInventory(index);
}

void zapi::Player::pickUpResource(RESOURCE_NUMBER index)
{
    tile->removeResource(index);
    addInventory(index);
}

sf::Vector2f zapi::Player::getPosition(void)
{
    return position;
}

void zapi::Player::updateOrientation(ORIENTATION direction)
{
    orientation = direction;
}
