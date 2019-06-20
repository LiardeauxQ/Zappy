/*
** EPITECH PROJECT, 2019
** Team.hpp
** File description:
** Team header
*/

#pragma once

#include "Player.hpp"
#include <vector>
#include <memory>
#include <list>

namespace zapi
{
    class Team {
        public:
            Team(const std::string &name = "trash");
            ~Team() = default;
            void addPlayer(int id, zapi::Tile *tile, const sf::Vector2f &position);
            std::string &getName() { return name; };
            std::list<Player> getPlayers() { return players; };
            bool checkPlayer(unsigned int id);
            zapi::Player &getPlayer(unsigned int id);
            void removePlayer(unsigned int id);
        private:
            std::string name;
            std::list<Player> players;
    };
}
