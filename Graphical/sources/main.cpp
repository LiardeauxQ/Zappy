/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main
*/

#include "InputParser.hpp"
#include "ServerInteraction.hpp"
#include "App.hpp"

int main(int ac, char **av)
{
    IO::InputParser iParser(ac, av);
    communication::ServerInteraction interaction(iParser.getCmdIntOption("-p"),
            iParser.getCmdStringOption("-h"));
    App app("Zappy", interaction, 5);

    app.start();
    return (0);
}
