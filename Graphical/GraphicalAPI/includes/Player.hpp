/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** Player header
*/

#pragma once

#include <array>
#include "Entity.hpp"
#include "Tile.hpp"

namespace zapi
{
    class Player : public Entity {
        public:
            Player(unsigned int id, zapi::Tile *tile, unsigned int width, unsigned int height, const sf::Vector2f &position = sf::Vector2f(0, 0));
            ~Player() = default;
            void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            void move(ORIENTATION direction);
            void addInventory(RESOURCE_NUMBER index);
            void removeInventory(RESOURCE_NUMBER index);
            unsigned int getId() { return id; };
            void resetTile(zapi::Tile *tile);
            void levelUp(void);
            void dropResource(RESOURCE_NUMBER index);
            void pickUpResource(RESOURCE_NUMBER index);
            void updateOrientation(ORIENTATION direction);
            void updatePosition(const sf::Vector2f &new_pos);
            void updateResources(std::array<int, 7> &new_resources);
            sf::Vector2f getPosition();

        private:
            ORIENTATION orientation;
            int level;
            unsigned int id;
            sf::Sprite sprite;
            Tile *tile;
            std::array<int, 7> inventory {{0, 0, 0, 0, 0, 0, 0}};
            unsigned int width;
            unsigned int height;
    };
}
