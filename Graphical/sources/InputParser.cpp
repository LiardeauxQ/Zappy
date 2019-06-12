/*
** Handle input parsing
** EPITECH PROJECT, 2018
** InputParser.cpp
** File description:
*/

#include "InputParser.hpp"

namespace IO {
    static const std::vector<std::tuple<std::string, std::string>> arguments = {
        std::make_tuple(std::string("-p"), std::string("-port")),
        std::make_tuple(std::string("-n"), std::string("-name")),
        std::make_tuple(std::string("-h"), std::string("-hostname")),
        std::make_tuple(std::string(""), std::string("-help"))
    };
}

IO::InputParser::InputParser(int ac, char **av)
{
    for (int i = 1 ; i < ac ; i++)
        tokens.push_back(std::string(av[i]));
}

const std::string IO::InputParser::getCmdStringOption(const std::string &option) const
{
    for (size_t i = 0 ; i < tokens.size() ; i++) {
        if (tokens[i] == option && IO::isAnArgument(option))
            return (tokens[i + 1]);
    }
    return (std::string(""));
}

const std::string IO::InputParser::getCmdStringOption(const std::string &shortOption,
        const std::string &longOption) const
{
    for (size_t i = 0 ; i < tokens.size() ; i++) {
        if ((tokens[i] == shortOption && IO::isAnArgument(shortOption))
                || (tokens[i] == longOption && IO::isAnArgument(longOption)))
            return (tokens[i + 1]);
    }
    return (std::string(""));
}

int IO::InputParser::getCmdIntOption(const std::string &option) const
{
    for (size_t i = 0 ; i < tokens.size() ; i++) {
        if (tokens[i] == option && IO::isAnArgument(option))
            return (std::stoi(tokens[i + 1]));
    }
    return (0);
}

int IO::InputParser::getCmdIntOption(const std::string &shortOption,
        const std::string &longOption) const
{
    for (size_t i = 0 ; i < tokens.size() ; i++) {
        if ((tokens[i] == shortOption && IO::isAnArgument(shortOption))
                || (tokens[i] == longOption && IO::isAnArgument(longOption)))
            return (std::stoi(tokens[i + 1]));
    }
    return (0);
}

bool IO::isAnArgument(const std::string &option)
{
    for (auto arg : arguments ) {
        if (option == std::get<0>(arg) || option == std::get<1>(arg))
            return (true);
    }
    return (false);
}
