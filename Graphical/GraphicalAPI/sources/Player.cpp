/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player implementation
*/

#include "Player.hpp"

zapi::Player::Player(const float &radius, const sf::Vector2f &position)
: Entity(position)
, radius(radius)
    , main(radius)
    {
        main.setFillColor(sf::Color::Blue);
        main.setOutlineColor(sf::Color::Black);
        main.setOutlineThickness(1);
    main.setPosition(position);
}

void zapi::Player::update(sf::RenderWindow *window)
{
    window->draw(main);
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
