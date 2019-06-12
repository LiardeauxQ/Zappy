/*
** EPITECH PROJECT, 2018
** Errors.hpp
** File description:
** Errors header
*/

#include <exception>
#include <string>

class ServerInteractionErrors: public std::exception {
public:
    ServerInteractionErrors(std::string const &msg);
    ~ServerInteractionErrors() = default;

    const char *what() const noexcept override { return this->message.data(); }
private:
    std::string message;
};
