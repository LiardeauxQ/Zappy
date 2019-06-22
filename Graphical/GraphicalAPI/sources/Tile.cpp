/*
** EPITECH PROJECT, 2019
** Tile.cpp
** File description:
** Tile implementation
*/

#include <cstdlib>
#include "Tile.hpp"

zapi::Tile::Tile(const sf::Vector2f &size, const sf::Vector2f &position)
: Entity(position)
, size(size)
, main(size)
, selectedOutline(size)
, resources()
, isSelected(false)
//, sprite()
{
    sprite.setTexture(*(getTileTexture()));
    sprite.setTextureRect(sf::IntRect((std::rand() % 3) * 100, 0, 100, 100));
    sprite.setPosition(position);

//    shadow.setTexture(*(getTileTexture()));
//    shadow.setPosition(position);

    main.setPosition(position);
    main.setFillColor(sf::Color(218, 212, 187, 255));
    main.setOutlineThickness(1);
    main.setOutlineColor(sf::Color(78, 75, 66, 255));
    selectedOutline.setPosition(position);
    selectedOutline.setFillColor(sf::Color::Yellow);
    // selectedOutline.setOutlineThickness(5);
    // selectedOutline.setOutlineColor(sf::Color::Yellow);
    for (int i = 0; i != 7; i++)
        resources.push_back(Resource(i, position + sf::Vector2f((float)(std::rand()%((int)size.x - (int)(96 * 0.2))), (float)(std::rand()%((int)size.y - (int)(96 * 0.2))))));
}

void zapi::Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (!isSelected)
        target.draw(main, states);
    target.draw(sprite, states);
    if (isSelected)
        target.draw(selectedOutline, states);
//    target.draw(shadow, states);
}

void zapi::Tile::removeResource(RESOURCE_NUMBER index)
{
    resources[index]--;
}

void zapi::Tile::addResource(RESOURCE_NUMBER index)
{
    resources[index]++;
}

void zapi::Tile::updateResource(const std::vector<int> &res)
{
    if (res.size() != 7)
        return;
    for (int i = 0; i < 7; i++)
        resources[i] = res[i];
}

void zapi::Tile::selected(void)
{
    isSelected = true;
}

void zapi::Tile::unselected(void)
{
    isSelected = false;
}