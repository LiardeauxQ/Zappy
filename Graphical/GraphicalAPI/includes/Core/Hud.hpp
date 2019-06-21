/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Hud
*/

#pragma once

#include "Utils.hpp"

namespace zapi
{
    class Hud : public sf::Drawable {
        public:
            Hud();
            virtual ~Hud() = default;
        protected:
            sf::Texture texture;
            sf::Sprite sprite;
    };
}