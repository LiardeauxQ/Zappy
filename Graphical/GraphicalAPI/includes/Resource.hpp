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
            Resource(unsigned int id, const sf::Vector2f &position = sf::Vector2f(0, 0));
            ~Resource() = default;
            void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            unsigned int getQuantity(void);
            Resource &operator++(int);
            Resource &operator--(int);
            Resource &operator=(int amount);
        private:
            unsigned int quantity;
            sf::Sprite sprite;
    };
}
