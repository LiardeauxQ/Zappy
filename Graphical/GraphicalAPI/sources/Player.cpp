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
, radius(25)
, main(radius)
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

void zapi::Player::addInventory(int index, int quantity)
{
    inventory[index] += quantity;
}

void zapi::Player::removeInventory(int index, int quantity)
{
    inventory[index] -= quantity;
}