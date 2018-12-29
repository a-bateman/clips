//mvf v1
//Move File program for CLI.
//Written by: Andrew B.
//Originally written: 11-26-18
//Licensed under the BSD 3 clause license. It is expected that you have read the license file included with this source code before modifying, compiling or distributing it.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

inline void help()
{
    std::cout << n"\nmvf v1 Info:\n"
    << "\nReleased under BSD 3 clause license.  Please see the license file for details.\n\n\n"
    << "mvf is designed to move a file to a new location.  It will then remove the origional file.\n"
    << "You may call mvf with both the file to be moved and then the final location of the file as arguments.\n"
    << "You may call mvf on it's own and then input the file to move as well as the final location of the file.\n"
    << "EXAMPLE: ./pfc ./file-to-print ./final-file-location\n"
    << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n\n";
};

inline void getFiles(char& infil, std::string& filt)
{
    std::cout << "What file would you like to move? ";
    std::cin >> infil;
    std::cout << "Where would you like the file contents to copied to? ";
    std::cin >> filt;
};

inline void moveFile(std::string& filf, std::string& filt, char& infil, std::ifstream& rofil, std::ofstream& wofil)
{
        std::string syscom = "rm ";
        filf = infil;
        rofil.open(filf);
        wofil.open(filt);
        wofil << rofil.rdbuf();
        rofil.close();
        wofil.close();
        syscom = syscom + infil;
        if(system(syscom.c_str()) != 0)
        {
            std::cout << "Could not remove the origional file!" << std::endl;
        }
};

inline void arg2infil(char& infil, char& argv[], std::string& filt)
{
    strcpy(infil, argv[1]);
    filt = argv[2];
};


int main(int argc, char** argv)
{
    std::string *filf, *filt;
    std::ifstream* rofil;
    std::ofstream* wofil;
    char* infil[15];

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
            getFiles(filf, filt);
        }
        else
        {
            arg2infil(infil, argv, filt);
        }
        moveFile(filf, filt, infil, rofil, wofil);
        return 0;
}
