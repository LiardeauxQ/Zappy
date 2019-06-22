/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Hud
*/

#include <iostream>
#include "Core/Hud.hpp"

zapi::Hud::Hud():
isDraw(false)
, tile(nullptr)
, player(nullptr)
{
    initializeBackground();
    initializeText();
    for (int i = 0; i < 7; i++) {
        resources.push_back(Resource(i, sf::Vector2f((i * 120) + 40, 130), 1, true));
        initializeResourceOutputs(i);
    }
}

void zapi::Hud::initializeResourceOutputs(int i)
{
    resourceOutputs.push_back(sf::Text());
        resourceOutputs[i].setFont(*(getFont()));
        resourceOutputs[i].setCharacterSize(70);
        resourceOutputs[i].setFillColor(sf::Color::White);
        resourceOutputs[i].setString("0");
        resourceOutputs[i].setPosition(sf::Vector2f((i * 120) + 65, 210));
}

void zapi::Hud::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (!isDraw)
        return;
    target.draw(background);
    target.draw(text);
    target.draw(tileTitle);
    for (auto &resource : resources)
        target.draw(resource, states);
    for (auto &resourceOutput : resourceOutputs)
        target.draw(resourceOutput, states);
}

void zapi::Hud::updateResourceOutputs(void) //WIP!!
{
    for (int i = 0; i < 7; i++)
        resourceOutputs[i].setString(std::to_string(tile->getResources()[i].getQuantity()));
}

void zapi::Hud::initializeText(void)
{
    text.setFont(*(getFont()));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setString("Inventory  of ");
    text.setPosition(30, 30);
    tileTitle.setFont(*(getFont()));
    tileTitle.setCharacterSize(50);
    tileTitle.setFillColor(sf::Color::White);
    tileTitle.setString("Title");
    tileTitle.setPosition(230, 30);
}

void zapi::Hud::initializeBackground(void)
{
    background.setSize(sf::Vector2f(830, 300));
    background.setFillColor(sf::Color::Black);
    background.setOutlineColor(sf::Color::White);
    background.setOutlineThickness(5);
    background.setPosition(20, 20);
}

void zapi::Hud::switchDrawable(void)
{
    isDraw ? isDraw = false : isDraw = true;
}

void zapi::Hud::updateTilePtr(Tile *tile_ptr)
{
    tile = tile_ptr;
}

void zapi::Hud::setDrawable(bool draw)
{
    isDraw = draw;
}