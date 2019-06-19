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
    zapi::Game game("Zappy");
    game.start();
    return (0);

    // sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    // sf::Sprite sprite;
    // sf::Sprite copy;
    // sf::Texture texture;
    // sf::Event event;
    // zapi::Tile tile(sf::Vector2f(100, 100));
    // auto tmp = std::make_unique<zapi::Entity>(tile);
    // auto tm = std::make_unique<zapi::Entity>(zapi::Tile(sf::Vector2f(100, 100)));

    // texture.loadFromFile("sprites/grass.png", sf::IntRect(0, 0, 100, 100));
    // texture.setSmooth(true);
    // sprite.setTexture(texture);
    // copy.setTexture(texture);
    // copy.setPosition(0, 100);
    // while (window.isOpen()) {
    //     while(window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }
    //     window.clear();
    //     // window.draw(sprite);
    //     // window.draw(copy);
    //     // tmp->update(&window);
    //     // tm->update(&window);
    //     tile.update(&window);
    //     window.display();
    // }
    // return 0;
}
