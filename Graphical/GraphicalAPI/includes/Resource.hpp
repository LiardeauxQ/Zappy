/*
** EPITECH PROJECT, 2019
** Resource.hpp
** File description:
** Resource header
*/

#pragma once

#include "Entity.hpp"

#define MAX_RESOURCES 7

namespace zapi
{
    class Resource : public Entity {
        public:
            Resource(unsigned int id, const sf::Vector2f &position = sf::Vector2f(0, 0),
                    unsigned int quantity = 0);
            ~Resource() = default;
            void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            Resource &operator++(int);
            Resource &operator--(int);
        private:
            unsigned int quantity;
            sf::Sprite sprite;
    };
}
