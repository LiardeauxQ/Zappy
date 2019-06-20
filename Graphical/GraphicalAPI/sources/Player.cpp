/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player implementation
*/

#include "Player.hpp"

zapi::Player::Player(unsigned int id, zapi::Tile *tile, const sf::Vector2f &position)
: Entity(position)
, level(0)
, id(id)
, radius(25)
, main(radius)
, tile(tile)
, inventory()
{
    main.setFillColor(sf::Color::Blue);
    main.setOutlineColor(sf::Color::Black);
    main.setOutlineThickness(1);
    main.setPosition(position);
}

void zapi::Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(main, states);
}

void zapi::Player::move(ORIENTATION direction)
{
    switch (direction) {
        case NORTH:
            if (position.y - 100 > 0)
                main.setPosition(sf::Vector2f(position.x, position.y - 100));
            else
                main.setPosition(sf::Vector2f(position.x, 3000 - (50 + radius)));
            break;
        case EAST:
            if (position.x + 100 < 3000)
                main.setPosition(sf::Vector2f(position.x + 100, position.y));
            else
                main.setPosition(sf::Vector2f(0 + (50 - radius), position.y));
            break;
        case WEST:
            if (position.x - 100 > 0)
                main.setPosition(sf::Vector2f(position.x - 100, position.y));
            else
                main.setPosition(sf::Vector2f(3000 - (50 + radius), position.y));
            break;
        case SOUTH:
            if (position.y + 100 < 3000)
                main.setPosition(sf::Vector2f(position.x, position.y + 100));
            else
                main.setPosition(sf::Vector2f(position.x, 0 + (50 - radius)));
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