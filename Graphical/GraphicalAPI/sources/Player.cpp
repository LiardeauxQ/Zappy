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
    if (direction == NORTH) {
        main.move(0, -(radius * 4));
    }
    if (direction == EAST) {
        main.move(radius * 4, 0);
    }
    if (direction == WEST) {
        main.move(-(radius * 4), 0);
    }
    if (direction == SOUTH) {
        main.move(0, radius * 4);
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

unsigned int zapi::Player::getId(void)
{
    return id;
}