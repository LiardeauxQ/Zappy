/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window header
*/

#pragma once

#include "Tile.hpp"
#include "Team.hpp"
#include <string>
#include <vector>

namespace zapi
{
    class Menu {
        public:
            Menu();
            ~Menu() = default;
            void start();
            void loop();
            void event();


        private:
            sf::RenderWindow window;
            sf::Texture texture;
            sf::String playerInput; 
            sf::Texture buttonTexture;
            sf::RectangleShape rectangleButton;
            sf::IntRect rectSourceSprite;
            sf::Sprite buttonSprite;
            sf::Sprite sprite;
            sf::RectangleShape rectangle;
            std::string inputHostStr;
            std::string inputPortStr;
            sf::Text inputHost;
            sf::Text textButton;
            sf::Text inputPort;
            sf::Font font;
            bool clicked;


    };
}
