/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main
*/

#include <stdio.h>
#include "App.hpp"

int main(int ac, char **av)
{
    try {
        App app("Zappy", 20, 20);
        app.start();
    } catch (std::exception e) {
        std::cout << "Error to init connection" << std::endl;
    }
    return (0);
}
