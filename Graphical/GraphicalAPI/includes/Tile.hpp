/*
** EPITECH PROJECT, 2019
** Tile.hpp
** File description:
** Tile header
*/

#pragma once

#include "Resource.hpp"

namespace zapi
{
    class Tile : public Entity {
        public:
            Tile(const sf::Vector2f &size, const sf::Vector2f &position = sf::Vector2f(0, 0));
            ~Tile() = default;
            void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            std::vector<Resource> &getResources() { return resources; };
        private:
            sf::Vector2f size;
            sf::RectangleShape main;
            std::vector<Resource> resources;
            sf::Sprite sprite;
//            sf::Sprite shadow;
    };
}
