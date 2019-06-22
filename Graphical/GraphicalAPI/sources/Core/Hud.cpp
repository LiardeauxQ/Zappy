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
    initializeBackground();
    initializeText();
    for (int i = 0; i < 7; i++) {
        resources.push_back(Resource(i, sf::Vector2f((i * 120) + 40, 130), true));
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
    for (auto &resource : resources)
        target.draw(resource, states);
    for (auto &resourceOutput : resourceOutputs)
        target.draw(resourceOutput, states);
}

void zapi::Hud::initializeText(void)
{
    text.setFont(*(getFont()));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setString("Inventory  of ");
    text.setPosition(40, 30);
}

void zapi::Hud::initializeBackground(void)
{
    background.setSize(sf::Vector2f(830, 300));
    background.setFillColor(sf::Color::Black);
    background.setOutlineColor(sf::Color::White);
    background.setOutlineThickness(5);
    background.setPosition(20, 20);
}