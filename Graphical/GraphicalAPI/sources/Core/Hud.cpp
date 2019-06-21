/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Hud
*/

#include "Core/Hud.hpp"

zapi::Hud::Hud()
{
    for (int i = 0; i < 7; i++)
        resources.push_back(Resource(i, sf::Vector2f((i * 50) + 20, 30)));
}

void zapi::Hud::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &resource : resources)
        target.draw(resource, states);
}