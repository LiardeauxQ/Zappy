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
        virtual void update(const std::string &id, T data) = 0;
    };

    template <class T>
    class EventManager {
    public:
        EventManager(std::vector<std::string> ids)
        {
            for (std::string id : ids) {
                listeners.insert(std::make_pair(id,
                            std::vector<IEventListener<T>*>()));
            }
        }

        ~EventManager() = default;

        void subscribe(const std::string &id, IEventListener<T> *listener)
        {
            try {
                listeners.at(id).push_back(listener);
            } catch (std::exception e) {
                std::cout << e.what() << std::endl;
            }
        }

        void unsubscribe(const std::string &id, IEventListener<T> *listener)
        {
            try {
                listeners.at(id).remove(listener);
            } catch (std::exception e) {
                std::cout << e.what() << std::endl;
            }
        }

        void notify(const std::string &id, T data)
        {
            for (auto listener : listeners[id]) {
                listener->update(id, data);
            }
        }
    private:
        std::map<std::string, std::vector<IEventListener<T>*>> listeners;
    };
}
