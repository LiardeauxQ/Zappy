/*
** EPITECH PROJECT, 2019
** Utils.hpp
** File description:
** Utils header
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "protocols.h"

namespace zapi
{
    sf::Texture *getTileShadowTexture();
    sf::Texture *getTileTexture();
    sf::Texture *getResourceTexture();
    sf::Texture *getPlayerTexture();
}
