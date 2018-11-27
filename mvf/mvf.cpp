//mvf v1
//Move File program for CLI.
//Written by: Andrew B.
//Originally written: 11-26-18
//Licensed under the LOLicense.  It is expected that you have read the LOL-mvf.txt file included with this source code before modifying, compiling or distributing it.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

void help()
{
    std::cout << std::endl << std::endl << "mvf v1 Info:" << std::endl;
    std::cout << std::endl << std::endl << "Released under LOL License.  Please see the lol-mvf.txt file for details." << std::endl;
    std::cout << "mvf is designed to move a file to a new location.  It will then remove the origional file." << std::endl;
    std::cout << "You may call mvf with both the file to be moved and then the final location of the file as arguments." << std::endl;
    std::cout << "You may call mvf on it's own and then input the file to move as well as the final location of the file." << std::endl;
    std::cout << "EXAMPLE: ./pfc ./file-to-print ./final-file-location" << std::endl;
    std::cout << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root." << std::endl << std::endl;
};

int main(int argc, char** argv)
{
    std::string filf, filt;
    std::ifstream rofil;
    std::ofstream wofil;
    char infil[] = "./foo.bar";

    if(argc > 1 && argc == 2)
    {
        if(strncmp(argv[1], "help", 4) == 0 || strncmp(argv[1], "info", 4) == 0)
        {
            help();
            return 0;
        }
    }

        if(argc == 1)
        {
            std::cout << "What file would you like to move? ";
            std::cin >> infil;
            std::cout << "Where would you like the file contents to copied to? ";
            std::cin >> filt;
        }
        else
        {
            strcpy(infil, argv[1]);
            filt = argv[2];
        }
        filf = infil;
        rofil.open(filf);
        if(!rofil)
        {
            std::cout << "File to be moved does not exist!" << std::endl;
            return 0;
        }
        wofil.open(filt);
        wofil << rofil.rdbuf();
        rofil.close();
        wofil.close();
        if(remove(infil) != 0)
        {
            std::cout << "Could not remove the origional file!" << std::endl;
        }
        return 0;
}
