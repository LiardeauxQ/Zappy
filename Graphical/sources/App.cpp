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

void App::updateEngGame(char *data)
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

    updateGameMapSize(size);
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
    //TO DO: time management
}

void App::updateBroadcast(char *data)
{
    //TO DO: Broacast
}
