/*
** EPITECH PROJECT, 2019
** Animation.hpp
** File description:
** Animation header
*/

#pragma once

#include "Utils.hpp"
#include <memory>

namespace zapi
{
    enum PLAYER_ANIMATION {
        IDLE_NORTH = 1,
        IDLE_EAST = 2,
        IDLE_SOUTH = 3,
        IDLE_WEST = 4,
        MOVE_NORTH = 5,
        MOVE_EAST = 6,
        MOVE_SOUTH = 7,
        MOVE_WEST = 8
    };

    class Animation : public sf::Drawable {
        public:
            Animation(PLAYER_ANIMATION id, sf::Sprite &sprite, sf::Time frameLength);
            ~Animation() = default;
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            void update(sf::Time deltaTime);
            void addFrame(sf::IntRect frame);
            void setFrame(unsigned int index);
            void play();
        private:
            PLAYER_ANIMATION id;
            sf::Sprite sprite;
            std::vector<sf::IntRect> frames;
            unsigned int frameIndex;
            sf::Time frameLength;
            sf::Time currentTime;
    };
}
