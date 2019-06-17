/*
** EPITECH PROJECT, 2019
** Team.hpp
** File description:
** Team header
*/

#pragma once

#include "Player.hpp"
#include <vector>

namespace zapi
{
    class Team {
        public:
            Team();
            ~Team() = default;
            void addPlayer(Player *player);
            void addPlayer(Player &player);
        private:
            std::vector<Player *> players;
    };
}
