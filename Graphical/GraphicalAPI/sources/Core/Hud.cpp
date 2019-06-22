/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Hud
*/

#include "Core/Hud.hpp"

zapi::Hud::Hud():
isDraw(true)
{
    initializeText();
    for (int i = 0; i < 7; i++)
        resources.push_back(Resource(i, sf::Vector2f((i * 120) + 30, 120), true));
    initializeBackground();
}

void zapi::Hud::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (!isDraw)
        return;
    target.draw(background);
    target.draw(text);
    for (auto &resource : resources)
        target.draw(resource, states);
}

void zapi::Hud::initializeText(void)
{
    font.loadFromFile("fonts/arcadeClassic.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setString("Inventory");
    text.setPosition(200, 30);
}

void zapi::Hud::initializeBackground(void)
{
    background.setSize(sf::Vector2f(830, 300));
    background.setFillColor(sf::Color::Black);
    background.setOutlineColor(sf::Color::White);
    background.setOutlineThickness(5);
    background.setPosition(10, 10);
}