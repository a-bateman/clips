#ifndef commander_hpp 
#define commander_hpp 

#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <regex>

namespace CMD {
class commander {
public:
    explicit commander(const std::vector<std::string>& inputs);
    commander(int argc, char** argv);
    commander(int argc, const char** argv);
    size_t getFlagCount () const;
    bool isFlagSet (const std::string& flagName) const;
    std::string getFlagValue (const std::string& flagName) const;
    std::string getEverythingFrom (const std::string& flagName) const;
    std::string getEverythingFromTo (const std::string& flagName, const std::string& flagName2) const;
    int getFlagPosition (const std::string& flagName) const;
    std::vector<std::string> getAllFlagsLike (const std::regex& pattern) const;
    std::vector<std::string> getAllFlagsUnlike (const std::regex& pattern) const;
    std::string operator[] (const int index) const;
    typename std::vector<std::string>::const_iterator begin() const;
    typename std::vector<std::string>::const_iterator end() const;
private:
    std::vector<std::string> arguments;
};
}

#endif