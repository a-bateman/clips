//beg v1
//Beginning program for CLI.
//Written by: Andrew B.
//Originally written: 11-28-18
//Licensed under the BSD 3 clause license. It is expected that you have read the license file included with this source code before modifying, compiling or distributing it.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <commander.hpp>
#include <exception>

inline bool shouldDisplayHelp (const CMD::commander &args) {
    return(args.isFlagSet("help") || args.isFlagSet("info"));

}

inline bool helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args)) {
        std::cout << "\n\nbeg v1 Info:\n"
                  << "\nReleased under BSD 3 clause license.  Please see the license file for details.\n\n\n"
                  << "beg is designed to print the first 10 lines of a file to the screen.\n"
                  << "You may call beg on it's own and input the file to print as an arguement.\n"
                  << "EXAMPLE: ./beg ./file-to-print\n"
                  << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n";
        return true;
    }
    return false;
};

inline void inputFileName (std::string& filf) {
    std::cout << "What file would you like to print the contents of? ";
    std::cin >> filf;
}

inline std::ifstream openFile (const std::string& filf) {
    std::ifstream rofil;
    rofil.open(filf);
    if (!rofil) {
        std::cerr << "Cannot open file " << filf;
        throw;
    }
    return rofil;
}

inline void printLines (std::ifstream rofil, size_t amountOfLines = 10) {
    std::string line;
    for(int i = 0; i < amountOfLines; i++)
    {
        std::getline(rofil, line);
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
    rofil.close();
}

inline int getAmountOfLines (const CMD::commander &args) {
    std::string argument = args.getFlagValue("-l");
    if (argument == "")
        return 10;
    return std::stoi (argument);
}

int main(int argc, char** argv)
{
    CMD::commander args (argc-1, argv + 1);
    std::string filf;

    if(helpMessage(args))
        return 0;

    if(args.getFlagCount() < 1)
        inputFileName(filf);
    else
        filf = args.getAllFlagsUnlike(std::regex ("-\\w*"))[0];

    printLines (openFile(filf), getAmountOfLines(args));
    return 0;
}
