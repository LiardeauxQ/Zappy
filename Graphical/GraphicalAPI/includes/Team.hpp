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
            void addPlayer(int id, const sf::Vector2f &position);
            std::string &getName() { return name; };
            std::list<Player> getPlayers() { return players; };
        private:
            std::string name;
            std::list<Player> players;
    };
}
