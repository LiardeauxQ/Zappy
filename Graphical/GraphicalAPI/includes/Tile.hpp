/*
** EPITECH PROJECT, 2019
** Tile.hpp
** File description:
** Tile header
*/

#pragma once

#include "Entity.hpp"

namespace zapi
{
    class Tile : public Entity {
        public:
            Tile(const sf::Vector2f &size, const sf::Vector2f &position = sf::Vector2f(0, 0));
            ~Tile() = default;
            void update(sf::RenderWindow *window) final;
        private:
            sf::Vector2f size;
            sf::RectangleShape main;
    };
}
