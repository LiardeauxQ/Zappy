/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main
*/

#include "InputParser.hpp"
#include "ServerInteraction.hpp"
#include "Core/Game.hpp"

int main(int ac, char **av)
{
//    IO::InputParser iParser(ac, av);
//    communication::ServerInteraction interaction(iParser.getCmdIntOption("-p"),
//            iParser.getCmdStringOption("-h"));
//
//    interaction.requestMapSize();
//    interaction.requestTileContent();
//    interaction.requestMapContent();

    // sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    // sf::Sprite sprite;
    // sf::Sprite copy;
    // sf::Texture texture;
    // sf::Texture crystal;
    // sf::Event event;

    // texture.loadFromFile("sprites/grass.png", sf::IntRect(0, 0, 100, 100));
    // texture.setSmooth(true);
    // sprite.setTexture(texture);
    // crystal.loadFromFile("sprites/crystal.png", sf::IntRect(0, 0, 32, 64));
    // crystal.setSmooth(true);
    // copy.setTexture(crystal);
    // copy.setPosition(200, 200);
    // while (window.isOpen()) {
    //     while(window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }
    //     window.clear();
    //     window.draw(sprite);
    //     window.draw(copy);
    //     window.display();
    // }

    zapi::Game game("Zappy");
    game.start();
    return (0);
}
