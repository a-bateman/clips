//lfs v1
//List FileS for CLI.
//Written by: Andrew B.
//Originally written: 11-28-18
//Licensed under the BSD 3 clause license. It is expected that you have read the license file included with this source code before modifying, compiling or distributing it.

#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <commander.hpp>
#include <colorink.hpp>
#include <exception>

inline bool shouldDisplayHelp(const CMD::commander &args)
{
    return (args.isFlagSet("help") || args.isFlagSet("info"));
}

inline bool helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args))
    {
        std::cout << "\n\nlfs v1 Info:\n"
                  << "\nReleased under BSD 3 clause license.  Please see the license file for details.\n\n\n"
                  << "lfs is designed to list all of the files in a specific directory.\n"
                  << "You may call lfs on it's own and input the file to print as an arguement.\n"
                  << "EXAMPLE: ./lfs ./directory-to-print/\n"
                  << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n";
        return true;
    }
    return false;
};


bool isExecutable(const std::experimental::filesystem::directory_entry &entry)
{
    return ((entry.status().permissions() & std::experimental::filesystem::perms::owner_exec) == std::experimental::filesystem::perms::owner_exec) ||
           ((entry.status().permissions() & std::experimental::filesystem::perms::owner_exec) == std::experimental::filesystem::perms::owner_exec) ||
           ((entry.status().permissions() & std::experimental::filesystem::perms::owner_exec) == std::experimental::filesystem::perms::owner_exec);
}

std::string extractName(const std::string name)
{
    return name.substr(2, name.size());
}


INK::ColorMode getDatatypeColorCode(const std::experimental::filesystem::directory_entry &entry)
{

    switch (entry.status().type())
    {
    case std::experimental::filesystem::file_type::block:
        return INK::ColorMode(INK::COLOR::GREEN, INK::COLOR::BLACK);
    case std::experimental::filesystem::file_type::character:
        return INK::ColorMode(INK::COLOR::BLACK, INK::COLOR::BLUE);
    case std::experimental::filesystem::file_type::not_found:
        return INK::ColorMode(INK::COLOR::RED, INK::COLOR::YELLOW);
    case std::experimental::filesystem::file_type::regular:
        return INK::ColorMode(INK::COLOR::NONE, INK::COLOR::NONE);
    case std::experimental::filesystem::file_type::directory:
        return INK::ColorMode(INK::COLOR::BLACK, INK::COLOR::YELLOW);
    case std::experimental::filesystem::file_type::symlink:
        return INK::ColorMode(INK::COLOR::MAGENTA, INK::COLOR::BLUE);
    case std::experimental::filesystem::file_type::fifo:
        return INK::ColorMode(INK::COLOR::BLUE, INK::COLOR::WHITE);
    case std::experimental::filesystem::file_type::socket:
        return INK::ColorMode(INK::COLOR::GREEN, INK::COLOR::BLACK);
    case std::experimental::filesystem::file_type::unknown:
        return INK::ColorMode(INK::COLOR::RED, INK::COLOR::NONE);
    }
    return INK::ColorMode(INK::COLOR::WHITE, INK::COLOR::NONE);
}

inline void printFiles(std::string dir)
{
    namespace FS = std::experimental::filesystem;
    for (auto filename : FS::directory_iterator(dir))
        try
        {
            if (isExecutable (filename))
                std::cout << INK::underline;
            std::cout << getDatatypeColorCode(filename) << extractName(filename.path()) << INK::reset << "\n";
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << "\n";
        }
    std::cout << "\n";
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
