/*
** EPITECH PROJECT, 2019
** Animation.cpp
** File description:
** Animation implementation
*/

#include "Animation.hpp"

zapi::Animation::Animation(sf::Sprite &sprite, sf::Time frameLength, bool isLoop)
: sprite(sprite)
, frames()
, frameIndex(0)
, frameLength(frameLength)
, currentTime(sf::Time::Zero)
, currentCycle(0)
, duration(0)
, isLoop(isLoop)
, distance(0, 0)
{
}

void zapi::Animation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

bool zapi::Animation::update(sf::Time deltaTime)
{
    currentTime += deltaTime;
    if (!isLoop && currentCycle >= duration)
        return false;
    if (currentTime >= frameLength)
        setFrame(++frameIndex);
    return true;
}

void zapi::Animation::addFrame(sf::IntRect frame)
{
    frames.push_back(frame);
}

void zapi::Animation::setFrame(unsigned int index)
{
    if (index >= frames.size()) {
        frameIndex = 0;
        currentCycle++;
    }
    sprite.setTextureRect(frames[frameIndex]);
    sprite.setPosition(sf::Vector2f(sprite.getPosition().x + distance.x, sprite.getPosition().y + distance.y));
    currentTime -= frameLength;
}

void zapi::Animation::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
}

void zapi::Animation::setFrameLength(sf::Time newLength)
{
    frameLength = newLength;
}

void zapi::Animation::setIsLoop(bool value)
{
    isLoop = value;
}

void zapi::Animation::play(unsigned int cycle, sf::Vector2f endPosition)
{
    currentCycle = 0;
    duration = cycle;
    if (endPosition != sf::Vector2f(0, 0)) {
        distance = sf::Vector2f(endPosition.x - sprite.getPosition().x, endPosition.y - sprite.getPosition().y);
        distance = sf::Vector2f((distance.x/duration)/frames.size(), (distance.y/duration)/frames.size());
    } else
        distance = sf::Vector2f(0, 0);
    frameIndex = 0;
    setFrame(0);
}
