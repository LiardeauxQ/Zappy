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
            Menu(sf::RenderWindow &window);
            ~Menu() = default;
            void start();
            void loop();
            void setPositionButton();
            void detectedClick();
            void displayItems();
            void updateInputs();
            void detectInputs();
            bool getGameStart(void);
            std::string &getInputHost(void);
            std::string &getInputPort(void);

        private:
            bool checkPortHost(void);
            sf::RenderWindow *window;
            sf::String playerInput;
            sf::RectangleShape rectangleButton;
            sf::IntRect rectSourceSprite;
            sf::Sprite buttonSprite;
            sf::Sprite sprite;
            sf::RectangleShape rectangleHost;
            sf::RectangleShape rectanglePort;
            std::string inputHostStr;
            std::string inputPortStr;
            sf::Text inputHost;
            sf::Text textButton;
            sf::Text inputPort;
            sf::Text errorMsg;
            sf::Event event;
            bool clickedHost;
            bool clickedPort;
            bool gameStart;
            int error;
    };
}
