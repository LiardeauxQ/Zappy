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
    App(const std::string &title, communication::ServerInteraction &interaction);
    ~App() = default;

    void start();
    void loop();

    void update(const std::string &eventType, int id, char *data) override;

    void updateTileContent(char *data);
private:
    zapi::Window window;
    communication::ServerInteraction &server;
};
