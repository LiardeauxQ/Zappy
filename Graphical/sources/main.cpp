/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main
*/

#include "InputParser.hpp"
#include "ServerInteraction.hpp"
#include "Core/Window.hpp"
#include "Tile.hpp"

int main(int ac, char **av)
{
//    IO::InputParser iParser(ac, av);
//    communication::ServerInteraction interaction(iParser.getCmdIntOption("-p"),
//            iParser.getCmdStringOption("-h"));
//
//    interaction.requestMapSize();
//    interaction.requestTileContent();
//    interaction.requestMapContent();
    zapi::Window window("Zappy");

    for (int i = 0, x = 0, y = 0; i != 900; i++, x += 100) {
        if (x >= 3000) {
            x = 0;
            y += 100;
        }
        window.addEntity(new zapi::Tile(sf::Vector2f(100, 100), sf::Vector2f(x, y)));
    }
    
    window.startLoop();
    return (0);
}
