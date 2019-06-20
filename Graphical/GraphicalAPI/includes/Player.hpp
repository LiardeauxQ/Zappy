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
            Player(unsigned int id, const sf::Vector2f &position = sf::Vector2f(0, 0));
            ~Player() = default;
            void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            void move(ORIENTATION direction);
            void addInventory(int index, int quantity);
            void removeInventory(int index, int quantity);
            unsigned int getId() { return id; };

        private:
            unsigned int id;
            float radius;
            sf::CircleShape main;
            Tile *tile;
            std::array<int, 7> inventory {{0, 0, 0, 0, 0, 0, 0}};
    };
}
