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
    // server.events.subscribe("socket", this);
}

void App::start()
{
    loop();
}

void App::loop()
{
    while (window.isOpen()) {
        inputHandler();
        window.drawEntities(getTiles());
        for (auto &team : getTeams())
            window.drawEntities(team.getPlayers());
        window.updateHUD();
        window.display();
    }
}

void App::update(const std::string &eventType, int id, char *data)
{
    std::cout << "has been updated\n" << std::endl;
    if (id == SRV_TILE_CONTENT)
        updateTileContent(data);
}

void App::updateTileContent(char *data)
{
    std::vector<int> res;
    srv_tile_content_t *srv = (srv_tile_content_t*)data;
    sf::Vector2f pos(srv->x, srv->y);

    res.push_back(srv->q0);
    res.push_back(srv->q1);
    res.push_back(srv->q2);
    res.push_back(srv->q3);
    res.push_back(srv->q4);
    res.push_back(srv->q5);
    res.push_back(srv->q6);
    std::cout << "Update tile " << pos.x << " " << pos.y << std::endl;
    updateTile(pos, res);
}

void App::inputHandler(void)
{
    window.clear();
    while(window.pollEvent(window.getEvent())) {
        window.inputHandler();
        if (window.getEvent().type == sf::Event::MouseButtonPressed && window.getEvent().mouseButton.button == sf::Mouse::Left)
            updateHud();
    }
    window.setView(window.getCamera());
}

void App::updateHud(void)
{
     sf::Vector2f worldCoord = window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getCamera());

    if (checkInsideGrid(worldCoord)) {
        window.getHUD().updateTilePtr(findTile(worldCoord));
        window.getHUD().setDrawable(true);
    } else
        window.getHUD().setDrawable(false);
}