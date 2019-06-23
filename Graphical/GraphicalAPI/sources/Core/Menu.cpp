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
    rectangleButton(sf::Vector2f(840 + 190,540 + 47)),
    rectSourceSprite(0, 0, 190, 47),
    rectangleHost(sf::Vector2f(120, 50)),
    rectanglePort(sf::Vector2f(120, 50)),
    inputHostStr("Host : "),
    inputPortStr("Port : ")

{
        if (!buttonTexture.loadFromFile("Graphical/sprites/yellowSheet.png"))
            return;
        if (!texture.loadFromFile("Graphical/sprites/menu.png"))
            return;
        buttonSprite = sf::Sprite(buttonTexture,rectSourceSprite);
        sprite = sf::Sprite(texture);
        font.loadFromFile("Graphical/GraphicalAPI/sources/Core/font.ttf");
        buttonSprite.setPosition(sf::Vector2f(840, 540));      
        rectanglePort.setSize(sf::Vector2f(300, 47));
        rectangleHost.setSize(sf::Vector2f(600, 47));
        rectanglePort.setFillColor(sf::Color(212, 212, 212, 127));
        rectangleHost.setFillColor(sf::Color(212, 212, 212, 127));
        rectangleHost.setPosition(350, 400),
        rectanglePort.setPosition(1150, 400),
        inputHost.setCharacterSize(34);
        inputPort.setCharacterSize(34);
        inputHost.setColor(sf::Color::White);
        inputPort.setColor(sf::Color::White);
        inputPort.setPosition(1155, 402);
        inputHost.setPosition(355, 402);
        inputHost.setFont(font);
        inputPort.setFont(font);
        textButton.setCharacterSize(34);
        textButton.setColor(sf::Color::Black);
        textButton.setPosition(880, 540);
        textButton.setFont(font);
        textButton.setString("START");
        clickedHost = false;
        clickedPort = false;
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
            if (sf::Mouse::getPosition(window).x > 880 && sf::Mouse::getPosition(window).x < 880 + 190 && sf::Mouse::getPosition(window).y > 540 && sf::Mouse::getPosition(window).y <= 540 + 47) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    rectSourceSprite.top = 94;
                } else if (rectSourceSprite.top == 0)
                    rectSourceSprite.top = 47;
                } else
                    rectSourceSprite.top = 0;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                if (rectangleHost.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    clickedHost = true;
                else
                    clickedHost = false;
                if (rectanglePort.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    clickedPort = true;
                else
                    clickedPort = false;
            }
            if (event.type == sf::Event::TextEntered && clickedPort == true) {
                if (event.text.unicode >= 48 && event.text.unicode <= 57)
                    inputPortStr +=  (static_cast<char>(event.text.unicode));
                else if (event.text.unicode == 8 && inputPortStr.size() > 7)
                    inputPortStr = inputPortStr.substr(0, inputPortStr.size()-1);
            }
            inputPort.setString(inputPortStr);
            if (event.type == sf::Event::TextEntered && clickedHost == true) {
                if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 13)
                    inputHostStr += (static_cast<char>(event.text.unicode));
                else if (event.text.unicode == 8 && inputHostStr.size() > 7)
                    inputHostStr = inputHostStr.substr(0, inputHostStr.size()-1);
                else if (event.text.unicode == 13) {
                    clickedHost = false;
                    clickedPort = true;
                }
            }
            inputHost.setString(inputHostStr);
        }
        buttonSprite.setTextureRect(rectSourceSprite);
        window.clear();
        window.draw(sprite);
        window.draw(rectangleHost);
        window.draw(rectanglePort);
        window.draw(inputHost);
        window.draw(inputPort);
        window.draw(buttonSprite);
        window.draw(textButton);
        window.display();
    }
}
