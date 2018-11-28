//cmp v1
//Compare program for CLI.
//Written by: Andrew B.
//Originally written: 11-27-18
//Licensed under the LOLicense.  It is expected that you have read the LOL.txt file included with this source code before modifying, compiling or distributing it.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "commander.hpp"

inline bool shouldDisplayHelp (const CMD::commander &args) {
    return(args.isFlagSet("help") || args.isFlagSet("info"));

}

inline void helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args))
        std::cout << "\n\t\t\tcpf v1 Info: \n"
                << "\nReleased under LOL License.  Please see the lol-cpf.txt file for details.\n\n\n"
                << "cpf is designed to copy a file to a new location leaving the origional file intact.\n"
                << "You may call cpf with both the file to be copied and then the final location of the file as arguments.\n"
                << "You may call cpf on it's own and input the file to be copied and a location to copy it to.\n"
                << "EXAMPLE: ./cpf ./file-to-copy ../final-file-location\n"
                << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n\n";
};

inline void inputFileNames (std::string& fil1, std::string& fil2) {
        std::cout << "What is the first file you would like to compare the contents of? ";
        std::cin >> fil1;
        std::cout << "What is the second file you would like to compare the contents of? ";
        std::cin >> fil2;
}

inline int compFile (const std::string& fil1, const std::string& fil2) {
    std::ifstream wofil1;
    std::ifstream wofil2;
    std::string fline1, fline2;
    int i = 1;

    wofil1.open(fil1);
    wofil2.open(fil2);
    if(!wofil1 || !wofil2)
    {
        std::cout << "One or both of the files do not exist!\n";
        return -1;
    }
    while(!wofil1.eof() || !wofil2.eof())
    {
        std::getline(wofil1, fline1);
        std::getline(wofil2, fline2);
        if(fline1.compare(fline2) == !0)
        {
            std::cout << "Line " << i << " is not the same";
        }
        i++;
    }
    return 0;
}

int main(int argc, char** argv)
{
    CMD::commander args(argc, argv);
    std::string fil1, fil2;

    if (args.getFlagCount() == 2)
        helpMessage(args);
    else if(args.getFlagCount() == 1)
        inputFileNames (fil1, fil2);
    else
    {
        fil1 = args[1];
        fil2 = args[2];
    }
    return compFile (fil1, fil2);
}
