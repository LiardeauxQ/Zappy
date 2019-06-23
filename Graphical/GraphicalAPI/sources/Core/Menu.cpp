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
    : window(sf::VideoMode(1920, 1080), "Zappy"),
    rectangleButton(sf::Vector2f(190, 47)),
    rectSourceSprite(0, 0, 190, 47),
    rectangle(sf::Vector2f(120, 50)),
    inputHostStr("Bite"),
    inputPortStr("Bite")

{
        if (!buttonTexture.loadFromFile("Graphical/sprites/yellowSheet.png"))
            return;
        if (!texture.loadFromFile("Graphical/sprites/menu.png"))
            return;
        buttonSprite = sf::Sprite(buttonTexture,rectSourceSprite);
        sprite = sf::Sprite(texture);
        font.loadFromFile("Graphical/GraphicalAPI/sources/Core/font.ttf");
        
        rectangle.setSize(sf::Vector2f(800, 200));
        inputHost.setCharacterSize(68);
        inputPort.setCharacterSize(68);
        inputHost.setColor(sf::Color::Red);
        inputPort.setColor(sf::Color::Red);
        inputPort.setPosition(500, 500);
        inputHost.setFont(font);
        inputPort.setFont(font);
        clicked = false;


}


void zapi::Menu::start()
{
    loop();
}

void zapi::Menu::loop()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (rectangleButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    rectSourceSprite.top = 94;
                } else if (rectSourceSprite.top == 0)
                    rectSourceSprite.top = 47;
                } else
                    rectSourceSprite.top = 0;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                if (rectangle.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    clicked = true;
                else
                    clicked = false;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                if (rectangle.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    clicked = true;
                else
                    clicked = false;
            }
            if (event.type == sf::Event::TextEntered && clicked == true)
                if (event.text.unicode >= 48 && event.text.unicode <= 57)
                    inputPortStr +=  (static_cast<char>(event.text.unicode));
            }
            if (event.type == sf::Event::TextEntered && clicked == true)
                if (event.text.unicode < 128)
                    inputHostStr += (static_cast<char>(event.text.unicode));
            inputHost.setString(inputHostStr);
            inputPort.setString(inputPortStr);

        }
        buttonSprite.setTextureRect(rectSourceSprite);
        window.clear();
        window.draw(sprite);
        window.draw(rectangle);
        window.draw(inputHost);
        window.draw(inputPort);
    //    window.draw(buttonSprite);
        window.display();
    }
}
