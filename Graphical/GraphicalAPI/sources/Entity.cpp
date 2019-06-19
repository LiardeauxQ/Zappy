/*
** EPITECH PROJECT, 2019
** Entity.cpp
** File description:
** Entity implementation
*/

#include "Entity.hpp"
#include <iostream>

zapi::Entity::Entity(const sf::Vector2f &position)
: position(position)
{}

void zapi::Entity::update(sf::RenderWindow __attribute__((unused)) *window)
{}
