/*
** EPITECH PROJECT, 2018
** App.hpp
** File description:
** Application header
*/

#include "Core/Game.hpp"
#include "Core/Window.hpp"
#include "ServerInteraction.hpp"
#include "EventManager.hpp"
#include "protocols.h"

class App: public zapi::Game, public communication::IEventListener<char*> {
public:
    App(const std::string &title, communication::ServerInteraction &interaction, unsigned int width = 30, unsigned int height = 30);
    ~App() = default;

    void start();
    void loop();

    typedef void (App::*cmdServerFun)(char *data);

    void update(const std::string &eventType, int id, char *data) override;

    void updateTileContent(char *data);

    void updateLayingEgg(char *data);
    void updateLayedEgg(char *data);
    void updateHatchingEgg(char *data);
    void updateEggConnection(char *data);
    void updateEggHatchedDeath(char *data);
    void updateEndGame(char *data);
    void updatePlayerExpulsion(char *data);
    void updateStartIncantation(char *data);
    void updateEndIncantation(char *data);
    void updateMapSize(char *data);
    void updateNameTeam(char *data);
    void updatePlayerNewConnection(char *data);
    void updatePlayerDeath(char *data);
    void updatePlayerInventory(char *data);
    void updatePlayerLevel(char *data);
    void updatePlayerPosition(char *data);
    void updateResourceDroping(char *data);
    void updateResourceCollecting(char *data);
    void updateTime(char *data);
    void updateBroadcast(char *data);

    void inputHandler(void);
    void updateHud(void);
    void triggerEnd(std::string const &teamName);
private:
    zapi::Window window;
    communication::ServerInteraction &server;
<<<<<<< HEAD
    bool isEnded;
=======
    sf::Clock frameClock;
    sf::Time frameTime;
>>>>>>> develop
};
