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
    sprite.setTextureRect(sf::IntRect(0, 448 + (64 * orientation), 64, 64));
    sprite.setPosition(position);
}

void zapi::Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void zapi::Player::move(ORIENTATION direction)
{
    switch (direction) {
        case NORTH:
            if (position.y - 100 > 0)
                position = sf::Vector2f(position.x, position.y - 100);
            else
                position = sf::Vector2f(position.x, 3000 - 50 - 32);
            break;
        case EAST:
            if (position.x + 100 < 3000)
                position = sf::Vector2f(position.x + 100, position.y);
            else
                position = sf::Vector2f(0 + 50 - 32, position.y);
            break;
        case WEST:
            if (position.x - 100 > 0)
                position = sf::Vector2f(position.x - 100, position.y);
            else
                position = sf::Vector2f(3000 - 50 - 32, position.y);
            break;
        case SOUTH:
            if (position.y + 100 < 3000)
                position = sf::Vector2f(position.x, position.y + 100);
            else
                position = sf::Vector2f(position.x, 0 + 50 - 32);
            break;
    }
    updateOrientation(direction);
    sprite.setPosition(position);
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
    sprite.setTextureRect(sf::IntRect(0, 448 + (64 * orientation), 64, 64));
}
