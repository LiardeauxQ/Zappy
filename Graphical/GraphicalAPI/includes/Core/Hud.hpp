/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Hud
*/

#pragma once

#include "Utils.hpp"
#include "Resource.hpp"

namespace zapi
{
    class Hud : public sf::Drawable {
        public:
            Hud();
            virtual ~Hud() = default;
            void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
            void initializeBackground(void);
            void initializeText(void);
            void initializeResourceOutputs(int i);
        protected:
            std::vector<Resource> resources;
            std::vector<sf::Text> resourceOutputs;
            sf::RectangleShape background;
            sf::Text text;
            bool isDraw;
    };
}