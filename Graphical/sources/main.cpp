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
    game.addPlayer("Team", 0, sf::Vector2f(0, 0));
    game.addPlayer("Team", 1, sf::Vector2f(26, 12));
    game.start();
    return (0);
}
