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
        MOVE_WEST = 8,
        START_INCANTATION = 9,
        INCANTATION = 10,
        STOP_INCANTATION = 11,
        BROADCAST_NORTH = 12,
        BROADCAST_EAST = 13,
        BROADCAST_SOUTH = 14,
        BROADCAST_WEST = 15,
        DIE = 16,
        PICK_AND_DROP = 17,
        EGG = 18
    };

    class Animation : public sf::Drawable {
        public:
            Animation(PLAYER_ANIMATION id, sf::Sprite &sprite, sf::Time frameLength, bool isLoop = true);
            ~Animation() = default;
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            bool update(sf::Time deltaTime);
            void addFrame(sf::IntRect frame);
            void setFrame(unsigned int index);
            void setPosition(sf::Vector2f position);
            void setFrameLength(sf::Time newLength);
            void setIsLoop(bool value);
            void play(unsigned int cycle = 0, sf::Vector2f endPosition = sf::Vector2f(0, 0));
        private:
            PLAYER_ANIMATION id;
            sf::Sprite sprite;
            std::vector<sf::IntRect> frames;
            unsigned int frameIndex;
            sf::Time frameLength;
            sf::Time currentTime;
            unsigned int currentCycle;
            unsigned int duration;
            bool isLoop;
            sf::Vector2f distance;
    };
}
