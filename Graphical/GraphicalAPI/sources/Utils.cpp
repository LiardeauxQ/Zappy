/*
** EPITECH PROJECT, 2019
** Utils.cpp
** File description:
** Utils implementation
*/

#include "Utils.hpp"

sf::Texture *zapi::getTileTexture()
{
    static sf::Texture *tileTexture;

    if (!tileTexture) {
        tileTexture = new sf::Texture();
        tileTexture->loadFromFile("sprites/grass.png", sf::IntRect(0, 0, 100, 100));
        tileTexture->setSmooth(true);
    }
    return tileTexture;
}

sf::Texture *zapi::getResourceTexture()
{
    static sf::Texture *resourceTexture;

    if (!resourceTexture) {
        resourceTexture = new sf::Texture();
        resourceTexture->loadFromFile("sprites/crystal.png", sf::IntRect(0, 0, 32, 64));
        resourceTexture->setSmooth(true);
    }
    return resourceTexture;
}
