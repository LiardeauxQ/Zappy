/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Hud
*/

#pragma once

#include "Tile.hpp"
#include "Player.hpp"
#include "Utils.hpp"
#include "Resource.hpp"

namespace zapi
{
    class Hud : public sf::Drawable {
        public:
            Hud();
            virtual ~Hud() = default;
            void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            void switchDrawable(void);
            void setDrawable(bool draw);
            void updateTilePtr(Tile *tile_ptr);
            void updateResourceOutputs(void);
            void resetTilePtr(void);
            Tile *getTilePtr(void);
        protected:
            void initializeBackground(void);
            void initializeText(void);
            void initializeResourceOutputs(int i);
            std::vector<Resource> resources;
            std::vector<sf::Text> resourceOutputs;
            sf::RectangleShape background;
            sf::Text text;
            sf::Text tileTitle;
            bool isDraw;
            zapi::Tile *tile;
            zapi::Player *player;
    };
}