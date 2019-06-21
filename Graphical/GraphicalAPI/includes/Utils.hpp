/*
** EPITECH PROJECT, 2019
** Utils.hpp
** File description:
** Utils header
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace zapi
{
    enum ORIENTATION {
        NORTH = 1,
        EAST  = 2,
        SOUTH = 3,
        WEST  = 4
    };

    sf::Texture *getTileShadowTexture();
    sf::Texture *getTileTexture();
    sf::Texture *getResourceTexture();
    sf::Texture *getPlayerTexture();
}
