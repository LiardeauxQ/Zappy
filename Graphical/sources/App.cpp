/*
** EPITECH PROJECT, 2018
** App.hpp
** File description:
** App
*/

#include "App.hpp"

App::App(const std::string &title, communication::ServerInteraction &interaction) :
    zapi::Game(),
    window(title),
    server(interaction)
{
    server.events.subscribe("socket", this);
}

void App::start()
{
    loop();
}

void App::loop()
{
    while (window.isOpen()) {
        server.listenSocket();
        window.update();
        window.drawEntities(getTiles());
        for (auto &team : getTeams())
            window.drawEntities(team.getPlayers());
        window.display();
    }
}

void App::update(const std::string &id, char *data)
{
    std::cout << "has been updated\n" << std::endl;
}
