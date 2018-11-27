//cpf v1
//Print File Contents program for CLI.
//Written by: Andrew B.
//Originally written: 11-26-18
//Licensed under the LOLicense.  It is expected that you have read the LOL-pfc.txt file included with this source code before modifying, compiling or distributing it.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

void help()
{
    std::cout << "\n\t\tcpf v1 Info: \n"
              << "\n\t\t\tReleased under LOL License.  Please see the lol-cpf.txt file for details.\n"
              << "cpf is designed to copy a file to a new location leaving the origional file intact.\n"
              << "You may call cpf with both the file to be copied and then the final location of the file as arguments.\n"
              << "You may call cpf on it's own and input the file to be copied and a location to copy it to.\n"
              << "EXAMPLE: ./cpf ./file-to-copy ../final-file-location\n"
              << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n\n";
};

int main(int argc, char** argv)
{
    std::string filf, filt;
    std::ifstream rofil;
    std::ofstream wofil;

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
            std::cout << "What file would you like to copy the contents of? ";
            std::cin >> filf;
            std::cout << "Where would you like the file contents to copied to? ";
            std::cin >> filt;
        }
        else
        {
            filf = argv[1];
            filt = argv[2];
        }
        rofil.open(filf);
        if(!rofil)
        {
            std::cout << "File to be copied does not exist!\n";
            return 0;
        }
        wofil.open(filt);
        wofil << rofil.rdbuf();
        rofil.close();
        wofil.close();
        return 0;
}
