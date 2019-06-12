/*
** EPITECH PROJECT, 2018
** name
** File description:
** InputParser header
*/

#include <string>
#include <vector>
#include <tuple>
#include <sstream>

namespace IO {
    class InputParser {
    public:
        InputParser(int ac, char **av);
        ~InputParser() = default;

        const std::string getCmdStringOption(const std::string &option) const;
        const std::string getCmdStringOption(const std::string &shortOption,
                const std::string &longOption) const;
        int getCmdIntOption(const std::string &option) const;
        int getCmdIntOption(const std::string &shortOption,
                const std::string &longOption) const;
    private:
        std::vector<std::string> tokens;
    };

    bool isAnArgument(const std::string &option);
}
