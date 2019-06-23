/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main
*/

#include <stdio.h>
#include "InputParser.hpp"
#include "ServerInteraction.hpp"
#include "App.hpp"

int main(int ac, char **av)
{
    IO::InputParser iParser(ac, av);

    try {
        communication::ServerInteraction interaction(iParser.getCmdIntOption("-p"),
                iParser.getCmdStringOption("-h"));
        srv_map_size_t map = interaction.requestMapSize();
        std::cout << map.x << " " << map.y << std::endl;
        interaction.setNonBlockingSocket();
        App app("Zappy", interaction, map.x, map.y);

        app.start();
        app.triggerEnd("test");

    } catch (std::exception e) {
        std::cout << "Error to init connection" << std::endl;
    }
    return (0);
}
