#include "commander.hpp"

namespace CMD
{
commander::commander(const std::vector<std::string> &inputs)
{
    arguments = inputs;
}
commander::commander(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
        arguments.push_back(std::string(argv[i]));
}
commander::commander(int argc, const char **argv)
{
    for (int i = 0; i < argc; i++)
        arguments.push_back(std::string(argv[i]));
}
size_t commander::getFlagCount() const 
{
    return arguments.size();
}
bool commander::isFlagSet(const std::string &flagName) const
{
    return (std::find(arguments.begin(), arguments.end(), flagName) != arguments.end());
}
std::string commander::getFlagValue(const std::string &flagName) const
{
    auto temp = std::find(arguments.begin(), arguments.end(), flagName);
    if (temp == arguments.end())
        return "";
    return *(temp + 1);
}
std::string commander::getEverythingFrom(const std::string &flagName) const
{
    std::string temp;
    for (auto i = std::find(arguments.begin(), arguments.end(), flagName) + 1; i != arguments.end(); i++)
        temp += (*i) + " ";
    return temp;
}
std::string commander::getEverythingFromTo(const std::string &flagName, const std::string &flagName2) const
{
    std::string temp;
    for (auto i = std::find(arguments.begin(), arguments.end(), flagName) + 1; i != std::find(arguments.begin(), arguments.end(), flagName2); i++)
        temp += (*i) + " ";
    return temp;
}
int commander::getFlagPosition(const std::string &flagName) const
{
    return std::distance(arguments.begin(), std::find(arguments.begin(), arguments.end(), flagName));
}
std::vector<std::string> commander::getAllFlagsLike(const std::regex &pattern) const
{
    std::vector<std::string> temp;
    for (const auto &i : arguments)
        if (std::regex_match(i, pattern))
            temp.push_back(i);
    return temp;
}
std::vector<std::string> commander::getAllFlagsUnlike(const std::regex &pattern) const
{
    std::vector<std::string> temp;
    for (const auto &i : arguments)
        if (!std::regex_match(i, pattern))
            temp.push_back(i);
    return temp;
}
std::string commander::operator[](const int index) const
{
    return arguments[index];
}
typename std::vector<std::string>::const_iterator commander::begin() const
{
    return arguments.begin();
}
typename std::vector<std::string>::const_iterator commander::end() const
{
    return arguments.end();
}
} // namespace CMD