/*
** EPITECH PROJECT, 2019
** Tile.hpp
** File description:
** Tile header
*/

#pragma once

#include "Resource.hpp"
#include <memory>

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
            std::vector<std::shared_ptr<Entity>> resources;
            sf::Texture texture;
            sf::Sprite sprite;
    };
}
