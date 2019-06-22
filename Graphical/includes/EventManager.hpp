/*
** EPITECH PROJECT, 2018
** EventManager.hpp
** File description:
** EventManager header
*/

#pragma once

#include <string>
#include <list>
#include <map>
#include <vector>
#include <exception>
#include <iostream>
#include <functional>

namespace communication {

    template <class T>
    class IEventListener {
    public:
        virtual void update(const std::string &eventType, int id, T data) = 0;
    };

    template <class T>
    class EventManager {
    public:
        EventManager(std::vector<std::string> eventTypes)
        {
            for (std::string eventType : eventTypes) {
                listeners.insert(std::make_pair(eventType,
                            std::vector<IEventListener<T>*>()));
            }
        }

        ~EventManager() = default;

        void subscribe(const std::string &eventType, IEventListener<T> *listener)
        {
            try {
                listeners.at(eventType).push_back(listener);
            } catch (std::exception e) {
                std::cout << e.what() << std::endl;
            }
        }

        void unsubscribe(const std::string &eventType, IEventListener<T> *listener)
        {
            try {
                listeners.at(eventType).remove(listener);
            } catch (std::exception e) {
                std::cout << e.what() << std::endl;
            }
        }

        void notify(const std::string &eventType, int id, T data)
        {
            for (auto listener : listeners[eventType]) {
                listener->update(eventType, id, data);
            }
        }
    private:
        std::map<std::string, std::vector<IEventListener<T>*>> listeners;
    };
}
