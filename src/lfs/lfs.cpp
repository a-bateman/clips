//lfs v1
//List FileS for CLI.
//Written by: Andrew B.
//Originally written: 11-28-18
//Licensed under the LOLicense. It is expected that you have read the LOL.txt file included with this source code before modifying, compiling or distributing it.

#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <commander.hpp>
#include <exception>

std::string getDatatypeColorCode(const std::experimental::filesystem::directory_entry &entry);

inline bool shouldDisplayHelp(const CMD::commander &args)
{
    return (args.isFlagSet("help") || args.isFlagSet("info"));
}

inline bool helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args))
    {
        std::cout << "\n\nlfs v1 Info:\n"
                  << "\nReleased under LOL License.  Please see the lol.txt file for details.\n"
                  << "lfs is designed to list all of the files in a specific directory.\n"
                  << "You may call lfs on it's own and input the file to print as an arguement.\n"
                  << "EXAMPLE: ./lfs ./directory-to-print/\n"
                  << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n";
        return true;
    }
    return false;
};

inline void inputDirectoryName(std::string &dir)
{
    std::cout << "Which directory would you like to print the contents of? ";
    std::cin >> dir;
}

std::string extractName(const std::string name)
{
    return name.substr(2, name.size());
}

inline void printFiles(std::string dir)
{
    namespace FS = std::experimental::filesystem;
    for (auto filename : FS::directory_iterator(dir))
        try
        {
            std::cout << getDatatypeColorCode(filename) << extractName(filename.path()) << "\e[0m\n";
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << "\n";
        }
}

int main(int argc, char **argv)
{
    CMD::commander args(argc - 1, argv + 1);
    std::string dir;

    if (helpMessage(args))
        return 0;

    if (args.getFlagCount() == 0)
        dir = ".";
    else
        dir = args.getAllFlagsUnlike(std::regex("-\\w*"))[0];

    printFiles(dir);
    return 0;
}

bool isExecutable(const std::experimental::filesystem::directory_entry &entry)
{
    return ((entry.status().permissions() & std::experimental::filesystem::perms::owner_exec) == std::experimental::filesystem::perms::owner_exec) ||
           ((entry.status().permissions() & std::experimental::filesystem::perms::owner_exec) == std::experimental::filesystem::perms::owner_exec) ||
           ((entry.status().permissions() & std::experimental::filesystem::perms::owner_exec) == std::experimental::filesystem::perms::owner_exec);
}

// The codes for foreground and background colours are:

//          foreground background
// black        30         40
// red          31         41
// green        32         42
// yellow       33         43
// blue         34         44
// magenta      35         45
// cyan         36         46
// white        37         47

// Additionally, you can use these:

// reset             0  (everything back to normal)
// bold/bright       1  (often a brighter shade of the same colour)
// underline         4
// inverse           7  (swap foreground and background colours)
// bold/bright off  21
// underline off    24
// inverse off      27

//source: https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal

std::string getDatatypeColorCode(const std::experimental::filesystem::directory_entry &entry)
{

    switch (entry.status().type())
    {
    case std::experimental::filesystem::file_type::block:
        return "\e[30;47m";
    case std::experimental::filesystem::file_type::character:
        return "\e[31;47m";
    case std::experimental::filesystem::file_type::not_found:
        return "\e[37;41m";
    case std::experimental::filesystem::file_type::regular:
        if (isExecutable(entry))
            return "\e[32;44m";
        return "\e[0m";
    case std::experimental::filesystem::file_type::directory:
        return "\e[4m\e[7m";
    case std::experimental::filesystem::file_type::symlink:
        return "\e[4m";
    case std::experimental::filesystem::file_type::fifo:
        return "\e[35;40m";
    case std::experimental::filesystem::file_type::socket:
        return "\e[32;40m";
    case std::experimental::filesystem::file_type::unknown:
        return "\e[34;47m";
    }
    return "";
}