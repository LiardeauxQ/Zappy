/*
** EPITECH PROJECT, 2018
** App.hpp
** File description:
** App
*/

#include <iostream>
#include "App.hpp"

static std::vector<std::tuple<int, App::cmdServerFun>> cmds = {
    std::make_tuple(SRV_MAP_SIZE, &App::updateMapSize),
    std::make_tuple(SRV_TILE_CONTENT, &App::updateTileContent),
    std::make_tuple(SRV_TEAMS_NAMES, &App::updateNameTeam),
    std::make_tuple(SRV_NEW_PLAYER_CONNECT, &App::updatePlayerNewConnection),
    std::make_tuple(SRV_PLAYER_POSITION, &App::updatePlayerPosition),
    std::make_tuple(SRV_PLAYER_LEVEL, &App::updatePlayerLevel),
    std::make_tuple(SRV_PLAYER_INVENTORY, &App::updatePlayerInventory),
    std::make_tuple(SRV_EXPULSION, &App::updatePlayerExpulsion),
    std::make_tuple(SRV_BROADCAST, &App::updateBroadcast),
    std::make_tuple(SRV_INCANTATION_START, &App::updateStartIncantation),
    std::make_tuple(SRV_INCANTATION_END, &App::updateEndIncantation),
    std::make_tuple(SRV_EGG_LAYING, &App::updateLayingEgg),
    std::make_tuple(SRV_RESOURCE_DROP, &App::updateResourceDroping),
    std::make_tuple(SRV_RESOURCE_COLLECT, &App::updateResourceCollecting),
    std::make_tuple(SRV_PLAYER_DEATH, &App::updatePlayerDeath),
    std::make_tuple(SRV_EGG_LAYED, &App::updateLayedEgg),
    std::make_tuple(SRV_EGG_HATCHING, &App::updateHatchingEgg),
    std::make_tuple(SRV_PLAYER_CONNECT_EGG, nullptr),
    std::make_tuple(SRV_PLAYER_DEATH_EGG, &App::updatePlayerDeath),
    std::make_tuple(SRV_TIME_UNIT_REQUEST, &App::updateTime),
    std::make_tuple(SRV_TIME_UNIT_CHANGE, &App::updateTime),
    std::make_tuple(SRV_END_GAME, &App::updateEndGame),
    std::make_tuple(SRV_MESSAGE_FROM_SRV, nullptr),
    std::make_tuple(SRV_UNKNOWN_COMMAND, nullptr),
    std::make_tuple(SRV_COMMAND_PARAMETER, nullptr),
    std::make_tuple(SRV_CUSTOM, nullptr)
};

App::App(const std::string &title, unsigned int width, unsigned int height) :
    zapi::Game(width, height),
    window(title, width, height),
    frameClock(),
    frameTime(),
    isEnded(false)
{
}

void App::start()
{
    loop();
}

void App::menuState(void)
{
    if (window.getMenu().getGameStart())
        return;
    window.getMenu().start();
    inputHost = window.getMenu().getInputHost().erase(0, 6);
    inputPort = window.getMenu().getInputPort().erase(0, 6);
    setupConnection();
}

void App::loop()
{
    while (window.isOpen()) {
        frameTime = frameClock.restart();
        server->listenSocket();
        menuState();
        inputHandler();
        window.drawEntities(getTiles());
        for (auto &team : getTeams())
            window.drawEntities(team.getPlayers(), frameTime);
        window.updateHUD();
        window.display();
    }
}

void App::setupConnection()
{
    server = new communication::ServerInteraction(std::stoi(inputPort), inputHost);
    server->events.subscribe("socket", this);
}

void App::update(const std::string &eventType, int id, char *data)
{
    cmdServerFun func;

    if (id == SRV_TILE_CONTENT)
        updateTileContent(data);
    for (auto elem : cmds) {
        if (std::get<0>(elem) == id) {
            func = std::get<1>(elem);
            ((*this).*(func))(data);
            break;
        }
    }
}

void App::updateTileContent(char *data)
{
    std::vector<int> res;
    srv_tile_content_t *srv = (srv_tile_content_t*)data;
    sf::Vector2f pos(srv->x * 100, srv->y * 100);

    res.push_back(srv->q0);
    res.push_back(srv->q1);
    res.push_back(srv->q2);
    res.push_back(srv->q3);
    res.push_back(srv->q4);
    res.push_back(srv->q5);
    res.push_back(srv->q6);
    updateTile(pos, res);
}

void App::updateLayingEgg(char *data)
{
    srv_player_egg_laying_t *srv = (srv_player_egg_laying_t*)data;

    eggLaying(srv->player_num);
}

void App::updateLayedEgg(char *data)
{
    srv_player_egg_layed_t *srv = (srv_player_egg_layed_t*)data;
    sf::Vector2f pos(srv->x * 100, srv->y * 100);

    eggLayed(srv->player_num, srv->egg_num, pos);
}

void App::updateHatchingEgg(char *data)
{
    srv_player_egg_hatching_t *srv = (srv_player_egg_hatching_t*)data;

    eggHatching(srv->egg_num);
}

void App::updateEggConnection(char *data)
{
    srv_player_egg_connection_t *srv = (srv_player_egg_connection_t*)data;

    eggHatched(srv->egg_num);
}

void App::updateEggHatchedDeath(char *data)
{
    srv_hatched_egg_death_t *srv = (srv_hatched_egg_death_t*)data;

    eggHatchedDeath(srv->egg_num);
}

void App::updateEndGame(char *data)
{
    srv_end_game_t *srv = (srv_end_game_t*)data;

    endGame(std::string(srv->winning_team));
}

void App::updatePlayerExpulsion(char *data)
{
    srv_player_expulsion_t *srv = (srv_player_expulsion_t*)data;

    expulsePlayer(srv->player_num);
}

void App::updateStartIncantation(char *data)
{
    srv_start_incantation_t *srv = (srv_start_incantation_t*)data;
    sf::Vector2f pos(srv->x * 100, srv->y * 100);
    std::array<int, MAX_PLAYERS> players;

    for (int i = 0 ; i < MAX_PLAYERS ; i++)
        players[i] = srv->players[i];
    startIncantation(srv->level, pos, players);
}

void App::updateEndIncantation(char *data)
{
    srv_end_incantation_t *srv = (srv_end_incantation_t*)data;
    sf::Vector2f pos(srv->x * 100, srv->y * 100);

    stopIncantation(srv->result, pos);
}

void App::updateMapSize(char *data)
{
    srv_map_size_t *srv = (srv_map_size_t*)data;
    sf::Vector2f size(srv->x, srv->y);
}

void App::updateNameTeam(char *data)
{
    srv_teams_names_t *srv = (srv_teams_names_t*)data;

    addTeam(std::string(srv->team_name));
}

void App::updatePlayerNewConnection(char *data)
{
    srv_new_player_connect_t *srv = (srv_new_player_connect_t*)data;
    sf::Vector2f pos(srv->x * 100, srv->y * 100);

    addPlayer(std::string(srv->team_name), srv->player_num, pos);
}

void App::updatePlayerDeath(char *data)
{
    srv_player_death_t *srv = (srv_player_death_t*)data;

    removePlayer(srv->player_num);
}

void App::updatePlayerInventory(char *data)
{
    srv_player_inventory_t *srv = (srv_player_inventory_t*)data;
    sf::Vector2f pos(srv->x * 100, srv->y * 100);
    std::array<int, MAX_PLAYERS> res;

    res[0] = srv->q0;
    res[1] = srv->q1;
    res[2] = srv->q2;
    res[3] = srv->q3;
    res[4] = srv->q4;
    res[5] = srv->q5;
    res[6] = srv->q6;
    updatePlayer(srv->player_num, pos, res);
}

void App::updatePlayerLevel(char *data)
{
    srv_player_level_t *srv = (srv_player_level_t*)data;

    levelUpPlayer(srv->player_num);
}

void App::updatePlayerPosition(char *data)
{
    srv_player_pos_t *srv = (srv_player_pos_t*)data;
    sf::Vector2f pos(srv->x * 100, srv->y * 100);

    updatePlayer(srv->player_num, pos, srv->orientation);
}

void App::updateResourceDroping(char *data)
{
    srv_player_resource_dropped_t *srv = (srv_player_resource_dropped_t*)data;

    dropResourcePlayer(srv->player_num, srv->resource);
}

void App::updateResourceCollecting(char *data)
{
    srv_player_resource_collected_t *srv = (srv_player_resource_collected_t*)data;

    pickUpResourcePlayer(srv->player_num, srv->resource);
}

void App::updateTime(char *data)
{
    srv_time_unit_request_t *srv = (srv_time_unit_request_t*)data;
    //TODO: time management
}

void App::updateBroadcast(char *data)
{
    //TODO: Broacast
}

void App::inputHandler(void)
{
    window.clear(sf::Color(78, 137, 232));
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

    if (checkInsideGrid(worldCoord) && window.getHUD().getTilePtr() != findTile(worldCoord)) {
        window.getHUD().updateTilePtr(findTile(worldCoord));
        window.getHUD().setDrawable(true);
    } else {
        window.getHUD().setDrawable(false);
        window.getHUD().resetTilePtr();
    }
}

void App::triggerEnd(std::string const &teamName)
{
    window.getHUD().setDrawable(false);
    window.getHUD().setEnd(teamName);
}
