//pfc v1
//Print File Contents program for CLI.
//Written by: Andrew B.
//Originally written: 11-26-18
//Licensed under the BSD 3 clause license. It is expected that you have read the license file included with this source code before modifying, compiling or distributing it.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

void help()
{
    std::cout << std::endl << std::endl << "pfc v1 Info:" << std::endl;
    std::cout << std::endl << std::endl << "Released under LOL License.  Please see the lol-pfc.txt file for details." << std::endl;
    std::cout << "pfc is designed to print the contents of a file to the screen." << std::endl;
    std::cout << "You may call pfc on it's own and input the file to print as an arguement." << std::endl;
    std::cout << "EXAMPLE: ./pfc ./file-to-print" << std::endl;
    std::cout << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root." << std::endl << std::endl;
};

int main(int argc, char** argv)
{
    std::string filf;
    std::ifstream rofil;

    if(argc > 1)
    {
        if(strncmp(argv[1], "help", 4) == 0 || strncmp(argv[1], "info", 4) == 0)
        {
            help();
            return 0;
        }
    }

        if(argc < 2)
        {
            std::cout << "What file would you like to print the contents of? ";
            std::cin >> filf;
        }
        else
        {
            filf = argv[1];
        }
        rofil.open(filf);
        std::cout << std::endl << "Printing contents of: " << filf << std::endl << std::endl;
        std::cout << rofil.rdbuf() << std::endl;
        rofil.close();
        std::cout << "EOF: " << filf << std::endl << std::endl;
        return 0;
}
