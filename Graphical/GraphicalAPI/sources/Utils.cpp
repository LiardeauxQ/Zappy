/*
** EPITECH PROJECT, 2019
** Utils.cpp
** File description:
** Utils implementation
*/

#include "Utils.hpp"

sf::Texture *zapi::getTileShadowTexture()
{
    static sf::Texture *tileShadowTexture;

    if (!tileShadowTexture) {
        tileShadowTexture = new sf::Texture();
        tileShadowTexture->create(100, 100);
        tileShadowTexture->setSmooth(true);
    }
    return tileShadowTexture;
}

sf::Texture *zapi::getTileTexture()
{
    static sf::Texture *tileTexture;

    if (!tileTexture) {
        tileTexture = new sf::Texture();
        tileTexture->loadFromFile("Graphical/sprites/grass.png");
        tileTexture->setSmooth(true);
    }
    return tileTexture;
}

sf::Texture *zapi::getResourceTexture()
{
    static sf::Texture *resourceTexture;

    if (!resourceTexture) {
        resourceTexture = new sf::Texture();
        resourceTexture->loadFromFile("Graphical/sprites/resources.png");
        resourceTexture->setSmooth(true);
    }
    return resourceTexture;
}

sf::Texture *zapi::getPlayerTexture()
{
    static sf::Texture *resourceTexture;

    if (!resourceTexture) {
        resourceTexture = new sf::Texture();
        resourceTexture->loadFromFile("Graphical/sprites/player.png");
        resourceTexture->setSmooth(true);
    }
    return resourceTexture;
}
