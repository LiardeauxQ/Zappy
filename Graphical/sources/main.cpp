/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main
*/

#include "InputParser.hpp"
#include "ServerInteraction.hpp"

int main(int ac, char **av)
{
    IO::InputParser iParser(ac, av);
    /*communication::ServerInteraction interaction(iParser.getCmdIntOption("-p"),
            iParser.getCmdStringOption("-h"));

    interaction.requestMapSize();*/
    return (0);
}
