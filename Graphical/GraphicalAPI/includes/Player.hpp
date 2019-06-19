/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** Player header
*/

#pragma once

#include <array>
#include "Entity.hpp"

namespace zapi
{
    class Player : public Entity {
        public:
            Player(unsigned int id, const sf::Vector2f &position = sf::Vector2f(0, 0));
            ~Player() = default;
            void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            void move(ORIENTATION direction);
            unsigned int getId() { return id; };

        private:
            unsigned int id;
            float radius;
            sf::CircleShape main;
            std::array<int, 7> inventory {{0, 0, 0, 0, 0, 0, 0}};
    };
}
