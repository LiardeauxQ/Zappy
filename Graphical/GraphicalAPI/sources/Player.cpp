/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Player implementation
*/

#include "Player.hpp"

zapi::Player::Player(unsigned int id, zapi::Tile *tile, unsigned int width, unsigned int height, const sf::Vector2f &position)
: Entity(position)
, orientation(SOUTH)
, level(0)
, id(id)
, sprite()
, tile(tile)
, inventory()
, width(width)
, height(height)
, animations()
{

    sprite.setTexture(*(getPlayerTexture()));
    sprite.setTextureRect(sf::IntRect(0, (64 * orientation), 64, 64));
    sprite.setPosition(position);
    for (int i = 1; i != 19; i++)
        createPlayerAnimation((PLAYER_ANIMATION)i);
    currentAnimation = getPlayerAnimation((PLAYER_ANIMATION)orientation);
    currentAnimation->play();
}

void zapi::Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void zapi::Player::move(ORIENTATION direction)
{
    sf::Vector2f newPosition;
    switch (direction) {
        case NORTH:
            if (position.y - 100 > 0)
                newPosition = sf::Vector2f(position.x, position.y - 100);
            else
                position = sf::Vector2f(position.x, (height * 100) - 50 - 32);
            break;
        case EAST:
            if (position.x + 100 < 3000)
                newPosition = sf::Vector2f(position.x + 100, position.y);
            else
                newPosition = sf::Vector2f(0 + 50 - 32, position.y);
            break;
        case WEST:
            if (position.x - 100 > 0)
                newPosition = sf::Vector2f(position.x - 100, position.y);
            else
                position = sf::Vector2f((width * 100) - 50 - 32, position.y);
            break;
        case SOUTH:
            if (position.y + 100 < height * 100)
                position = sf::Vector2f(position.x, position.y + 100);
            else
                newPosition = sf::Vector2f(position.x, 0 + 50 - 32);
            break;
    }
    updateOrientation(direction);
    updatePosition(newPosition);
    animations[orientation - 1].setPosition(position);
    currentAnimation = getPlayerAnimation((PLAYER_ANIMATION)(orientation + 4));
    currentAnimation->play(2, newPosition);
}

void zapi::Player::addInventory(RESOURCE_NUMBER index)
{
    inventory[index] += 1;
}

void zapi::Player::removeInventory(RESOURCE_NUMBER index)
{
    if (inventory[index] > 0)
        inventory[index] -= 1;
}

void zapi::Player::resetTile(zapi::Tile *tile)
{
    this->tile = tile;
}

void zapi::Player::levelUp(void)
{
    level++;
}

void zapi::Player::dropResource(RESOURCE_NUMBER index)
{
    currentAnimation = getPlayerAnimation(PLAYER_ANIMATION::PICK_AND_DROP);
    currentAnimation->play(1);
    tile->addResource(index);
    removeInventory(index);
}

void zapi::Player::pickUpResource(RESOURCE_NUMBER index)
{
    currentAnimation = getPlayerAnimation(PLAYER_ANIMATION::PICK_AND_DROP);
    currentAnimation->play(1);
    tile->removeResource(index);
    addInventory(index);
}

sf::Vector2f zapi::Player::getPosition()
{
    return sf::Vector2f(position.x - 18, position.y - 18);
}

void zapi::Player::updateOrientation(ORIENTATION direction)
{
    orientation = direction;
    sprite.setTextureRect(sf::IntRect(0, (64 * orientation), 64, 64));
}

void zapi::Player::broadcast()
{
    currentAnimation = getPlayerAnimation((PLAYER_ANIMATION)(orientation + 11));
    currentAnimation->play(1);
}

void zapi::Player::startIncantation()
{
    currentAnimation = getPlayerAnimation(PLAYER_ANIMATION::START_INCANTATION);
    currentAnimation->play(1);
}

void zapi::Player::incantation()
{
    currentAnimation = getPlayerAnimation(PLAYER_ANIMATION::INCANTATION);
    currentAnimation->play();
}

void zapi::Player::stopIncantation()
{
    currentAnimation = getPlayerAnimation(PLAYER_ANIMATION::STOP_INCANTATION);
    currentAnimation->play(1);
}

void zapi::Player::egg()
{
    currentAnimation = getPlayerAnimation(PLAYER_ANIMATION::EGG);
    currentAnimation->play();
}

void zapi::Player::updatePosition(const sf::Vector2f &newPos)
{
    position = newPos;
    sprite.setPosition(position);
    currentAnimation->setPosition(position);
}

void zapi::Player::updateResources(std::array<int, 7> &newResources)
{
    inventory = newResources;
}

bool zapi::Player::update(sf::Time elapsedTime)
{
    return currentAnimation->update(elapsedTime);
}

void zapi::Player::createPlayerAnimation(PLAYER_ANIMATION id)
{
    Animation animation(sprite, sf::seconds(0.10));
    switch (id) {
        case IDLE_NORTH:
            animation.addFrame(sf::IntRect(0, 0, 64, 64));
            break;
        case IDLE_EAST:
            animation.addFrame(sf::IntRect(0, 64, 64, 64));
            break;
        case IDLE_SOUTH:
            animation.addFrame(sf::IntRect(0, 128, 64, 64));
            break;
        case IDLE_WEST:
            animation.addFrame(sf::IntRect(0, 192, 64, 64));
            break;
        case MOVE_NORTH:
            animation.setFrameLength(sf::seconds(0.05));
            animation.setIsLoop(false);
            for (int i = 0; i != 8; i++)
                animation.addFrame(sf::IntRect((64 * i), 256, 64, 64));
            break;
        case MOVE_EAST:
            animation.setFrameLength(sf::seconds(0.05));
            animation.setIsLoop(false);
            for (int i = 0; i != 8; i++)
                animation.addFrame(sf::IntRect((64 * i), 320, 64, 64));
            break;
        case MOVE_SOUTH:
            animation.setFrameLength(sf::seconds(0.05));
            animation.setIsLoop(false);
            for (int i = 0; i != 8; i++)
                animation.addFrame(sf::IntRect((64 * i), 384, 64, 64));
            break;
        case MOVE_WEST:
            animation.setFrameLength(sf::seconds(0.05));
            animation.setIsLoop(false);
            for (int i = 0; i != 8; i++)
                animation.addFrame(sf::IntRect((64 * i), 448, 64, 64));
            break;
        case START_INCANTATION:
            for (int i = 0; i != 4; i++)
                animation.addFrame(sf::IntRect((64 * i), 512, 64, 64));
            break;
        case INCANTATION:
            for (int i = 0; i != 8; i++)
                animation.addFrame(sf::IntRect((64 * i), 576, 64, 64));
            break;
        case STOP_INCANTATION:
            for (int i = 1; i != 5; i++)
                animation.addFrame(sf::IntRect((64 * i), 640, 64, 64));
            break;
        case BROADCAST_NORTH:
            animation.setFrameLength(sf::seconds(3.0));
            animation.addFrame(sf::IntRect(0, 704, 64, 64));
            break;
        case BROADCAST_EAST:
            animation.setFrameLength(sf::seconds(3.0));
            animation.addFrame(sf::IntRect(0, 768, 64, 64));
            break;
        case BROADCAST_SOUTH:
            animation.setFrameLength(sf::seconds(3.0));
            animation.addFrame(sf::IntRect(0, 832, 64, 64));
            break;
        case BROADCAST_WEST:
            animation.setFrameLength(sf::seconds(3.0));
            animation.addFrame(sf::IntRect(0, 896, 64, 64));
            break;
        case DIE:
            animation.setFrameLength(sf::seconds(0.3));
            for (int i = 0; i != 5; i++)
                animation.addFrame(sf::IntRect((64 * i), 960, 64, 64));
            break;
        case PICK_AND_DROP:
            animation.setFrameLength(sf::seconds(0.25));
            for (int i = 0; i != 3; i++)
                animation.addFrame(sf::IntRect((64 * i), 1024, 64, 64));
            break;
        case EGG:
            animation.setFrameLength(sf::seconds(1.5));
            for (int i = 0; i != 5; i++)
                animation.addFrame(sf::IntRect((64 * i), 1088, 64, 64));
            break;
    }
    animations.push_back(animation);
}

std::shared_ptr<zapi::Animation> zapi::Player::getPlayerAnimation(PLAYER_ANIMATION id)
{
    return std::make_shared<Animation>(animations[id - 1]);
}
