/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player implementation
*/

#include "Player.hpp"

zapi::Player::Player(unsigned int id, zapi::Tile *tile, unsigned int width, unsigned int height, const sf::Vector2f &position)
: Entity(position)
, orientation(SOUTH)
, level(0)
, id(id)
, sprite()
, tile(tile)
, inventory()
, width(width)
, height(height)
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
                position = sf::Vector2f(position.x, (height * 100) - 50 - 32);
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
                position = sf::Vector2f((width * 100) - 50 - 32, position.y);
            break;
        case SOUTH:
            if (position.y + 100 < height * 100)
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

sf::Vector2f zapi::Player::getPosition()
{
    return sf::Vector2f(position.x - 18, position.y - 18);
}

void zapi::Player::updateOrientation(ORIENTATION direction)
{
    orientation = direction;
    sprite.setTextureRect(sf::IntRect(0, 448 + (64 * orientation), 64, 64));
}

void zapi::Player::updatePosition(const sf::Vector2f &new_pos)
{
    position = new_pos;
    sprite.setPosition(position);
}

void zapi::Player::updateResources(std::array<int, 7> &new_resources)
{
    inventory = new_resources;
}
