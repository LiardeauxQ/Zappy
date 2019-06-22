/*
** EPITECH PROJECT, 2019
** Game.cpp
** File description:
** Game implementation
*/

#include "Core/Menu.hpp"
#include <cstdlib>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

zapi::Menu::Menu()
{
}


void zapi::Menu::start()
{
    loop();
}

void zapi::Menu::loop()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Zappy");
    sf::Texture texture;
    sf::String playerInput;

    if (!texture.loadFromFile("Graphical/sprites/menu.png"))
        return;
    sf::Sprite sprite(texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
}
