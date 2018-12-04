//lfs v1
//List FileS for CLI.
//Written by: Andrew B.
//Originally written: 11-28-18
//Licensed under the LOLicense. It is expected that you have read the LOL.txt file included with this source code before modifying, compiling or distributing it.

#include <string>
#include <iostream>
#include <filesystem>
#include <string>
#include <commander.hpp>
#include <exception>

inline bool shouldDisplayHelp (const CMD::commander &args) {
    return(args.isFlagSet("help") || args.isFlagSet("info"));

}

inline bool helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args)) {
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

inline void inputDirectoryName (std::string& dir) {
    std::cout << "Which directory would you like to print the contents of? ";
    std::cin >> dir;
}


inline void printFiles(std::string dir) {
    namespace FS = std::filesystem;
    for(std::string filename : FS::directory_iterator(dir))
    {
        std::cout << filename << std::endl;
    }
}

int main(int argc, char** argv)
{
    CMD::commander args (argc-1, argv + 1);
    std::string dir;

    if(helpMessage(args))
        return 0;

    if(args.getFlagCount() < 1)
        inputDirectoryName(dir);
    else
        dir = args.getAllFlagsUnlike(std::regex ("-\\w*"))[0];

    printFiles(dir);
    return 0;
}
