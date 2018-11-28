//beg v1
//Beginning program for CLI.
//Written by: Andrew B.
//Originally written: 11-28-18
//Licensed under the LOLicense. It is expected that you have read the LOL.txt file included with this source code before modifying, compiling or distributing it.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

void help()
{
    std::cout << std::endl << std::endl << "beg v1 Info:" << std::endl;
    std::cout << std::endl << std::endl << "Released under LOL License.  Please see the lol.txt file for details." << std::endl;
    std::cout << "beg is designed to print the first 10 lines of a file to the screen." << std::endl;
    std::cout << "You may call beg on it's own and input the file to print as an arguement." << std::endl;
    std::cout << "EXAMPLE: ./beg ./file-to-print" << std::endl;
    std::cout << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root." << std::endl << std::endl;
};

int main(int argc, char** argv)
{
    std::ifstream rofil;
    std::string filf, line;
    int i = 0;

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
        for(i = 0; i != 9; i++)
        {
            std::getline(rofil, line);
            std::cout << line << std::endl;
        }
        std::cout << std::endl;
        rofil.close();
        return 0;
}
