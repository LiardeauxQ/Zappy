/*
** EPITECH PROJECT, 2019
** Resource.hpp
** File description:
** Resource header
*/

#pragma once

#include "Entity.hpp"

namespace zapi
{
    class Resource : public Entity {
        public:
            Resource(const sf::Vector2f &size, const sf::Vector2f &position = sf::Vector2f(0, 0));
            ~Resource() = default;
            void update(sf::RenderWindow *window);
        private:
            unsigned int quantity;
            sf::Vector2f size;
            sf::RectangleShape main;
    };
}
