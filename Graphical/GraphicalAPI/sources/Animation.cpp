/*
** EPITECH PROJECT, 2019
** Animation.cpp
** File description:
** Animation implementation
*/

#include "Animation.hpp"

zapi::Animation::Animation(PLAYER_ANIMATION id, sf::Sprite &sprite, sf::Time frameLength)
: id(id)
, sprite(sprite)
, frames()
, frameIndex(0)
, frameLength(frameLength)
, currentTime(sf::Time::Zero)
{
}

void zapi::Animation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void zapi::Animation::update(sf::Time deltaTime)
{
    currentTime += deltaTime;

    if (currentTime >= frameLength) {
        setFrame(++frameIndex);
    }
}

void zapi::Animation::addFrame(sf::IntRect frame)
{
    frames.push_back(frame);
}

void zapi::Animation::setFrame(unsigned int index)
{
    if (index >= frames.size())
        frameIndex = 0;
    sprite.setTextureRect(frames[frameIndex]);
    currentTime = sf::Time::Zero;
}

void zapi::Animation::play()
{
    frameIndex = 0;
    setFrame(0);
}
