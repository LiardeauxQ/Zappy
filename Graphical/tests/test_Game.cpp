/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** test_Game
*/

#include <criterion/criterion.h>
#include "Core/Game.hpp"
#include "Resource.hpp"

// Test(Game, addPlayer_test)
// {
//     zapi::Game game("test");
//     game.addPlayer("TeamTest", 22, sf::Vector2f(100, 1600));
//     cr_assert_eq(game.getPlayer(22).getId(), 22);
//     cr_assert_eq(game.getPlayer(22).getPosition().x, 100);
//     cr_assert_eq(game.getPlayer(22).getPosition().y, 1600);
// }

// Test(Game, getPlayer_wrong_id)
// {
//     zapi::Game game("test");
//     cr_assert_eq(game.getPlayer(2345).getId(), -1);
// }

Test(Resource, check_operators)
{
    zapi::Tile tile(sf::Vector2f(100, 100));
    tile.addResource(FOOD);
    tile.addResource(LINEMATE);
    std::vector<int> input {0, 1, 2, 3, 4, 5, 6};
    std::vector<zapi::Resource> test1 = tile.getResources();
    tile.updateResource(input);
    std::vector<zapi::Resource> test2 = tile.getResources();
    cr_assert_eq(test1[0].getQuantity(), 1);
    cr_assert_eq(test2[0].getQuantity(), 0);
    cr_assert_eq(test2[1].getQuantity(), 1);
    cr_assert_eq(test2[2].getQuantity(), 2);
    cr_assert_eq(test2[3].getQuantity(), 3);
    cr_assert_eq(test2[4].getQuantity(), 4);
    cr_assert_eq(test2[5].getQuantity(), 5);
    cr_assert_eq(test2[6].getQuantity(), 6);
}