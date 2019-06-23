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
    App app("Zappy", 5, 5);
    app.start();
    return (0);
}
