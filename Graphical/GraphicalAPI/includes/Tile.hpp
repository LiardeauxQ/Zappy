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
            sf::Vector2f getPosition(void) { return position; };
            std::vector<Resource> &getResources() { return resources; };
            void removeResource(RESOURCE_NUMBER index);
            void addResource(RESOURCE_NUMBER index);
            void updateResource(const std::vector<int> &res);
            void selected(void);
            void unselected(void);
        private:
            sf::Vector2f size;
            sf::RectangleShape main;
            sf::RectangleShape selectedOutline;
            std::vector<Resource> resources;
            sf::Sprite sprite;
            bool isSelected;
    };

}
