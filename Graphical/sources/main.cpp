/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main
*/

#include "InputParser.hpp"
#include "ServerInteraction.hpp"
#include "Core/Game.hpp"

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av)
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
}
