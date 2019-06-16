/*
** EPITECH PROJECT, 2019
** Entity.hpp
** File description:
** Entity header
*/

#pragma once

#include "Utils.hpp"

namespace zapi
{
    class Entity {
        public:
            Entity(const sf::Vector2f &position = sf::Vector2f(0, 0));
            virtual ~Entity() = default;
            virtual void update(sf::RenderWindow *window);
        protected:
            sf::Vector2f position;
    };
}
