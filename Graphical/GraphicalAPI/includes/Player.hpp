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
#include "Animation.hpp"

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
            void updatePosition(const sf::Vector2f &newPos);
            void updateResources(std::array<int, 7> &newResources);
            sf::Vector2f getPosition();
            ORIENTATION getOrientation() const { return orientation; };
            void broadcast();
            void startIncantation();
            void incantation();
            void stopIncantation();
            void egg();
    
            bool update(sf::Time elapsedTime);
            void createPlayerAnimation(PLAYER_ANIMATION id);
            std::shared_ptr<Animation> getPlayerAnimation(PLAYER_ANIMATION id);

            std::shared_ptr<Animation> currentAnimation;
        private:
            ORIENTATION orientation;
            int level;
            unsigned int id;
            sf::Sprite sprite;
            Tile *tile;
            std::array<int, 7> inventory {{0, 0, 0, 0, 0, 0, 0}};
            unsigned int width;
            unsigned int height;
            std::vector<Animation> animations;
    };
}
