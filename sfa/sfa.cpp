//sfa v1
//Simple File Appender program for CLI.
//Written by: Andrew B.
//Originally written: 11-20-18
//Licensed under the LOLicense.  It is expected that you have read the LOL-sfa.txt file included with this source code before modifying, compiling or distributing it.
//Special thanks to Maxi for commander.hpp (https://github.com/Wittmaxi/).
//WIP: Allow use of piped data as an input.

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <./headers/commander.hpp>


void help()
{
    std::cout << std::endl << std::endl << "sfa v1 Info:" << std::endl;
    std::cout << std::endl << std::endl << "Planned to be released out of house with the name SFA (Simple File Appender) under LOL License" << std::endl;
    std::cout << "***Highly Experimental: Not For Production Use!***" << std::endl;
    std::cout << "sfa is designed to append an unlimited number of files into a single specified file." << std::endl;
    std::cout << "You may pipe input from either a file or another program.  Expected format is as follows: " << std::endl;
    std::cout << "For piping data from a file: One file per line with the first in the list being the file appended to." << std::endl;
    std::cout << "For piping data from a CLI program: One file per stdin with the first in the list being the file appended to." << std::endl;
    std::cout << "You may call sfa on it's own and input the number of files during runtime." << std::endl;
    std::cout << "You may also call sfa using the file names as arguments." << std::endl;
    std::cout << "EXAMPLE: ./sfa ./file-appended-to ./first-file-appended-from ./second-file-appended-from ./etc.." << std::endl << std::endl << std::endl;
    std::cout << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root." << std::endl << std::endl;
};

int main(int argc, char** argv)
{
    int i, j, k, l = 0, numfiles;
    bool verbose;
    std::string filf[i], filt, line;
    std::ifstream rofil;
    std::ofstream wofil;

    if(argc > 1)
    {
        if(strncmp(argv[1], "help", 4) == 0 || strncmp(argv[1], "info", 4) == 0)
        {
            help();
            return 0;
        }
        if(strncmp(argv[1], "v", 2) || strncmp(argv[1], "V", 2))
        {
            verbose = true;
            std::cout << "Verbose mode enabled." << std::endl;
        }
    }

    if(!isatty(STDIN_FILENO))
    {

        std::cout << std::endl;
        if(argc < 3)
        {
            std::cout << "What file will we append to? ";
            std::cin >> filt;
            std::cout << "How many files will we be appending to the end of " << filt << "?  ";
            std::cin >> numfiles;
            for(i = 0; numfiles != 0; numfiles--)
            {
                std::cout << "What file will we append from? ";
                std::cin >> filf[i];
                i++;
            }
        }
        else
        {
            filt = argv[1];
            for(j = 2; argc - j != 0; j++)
            {
                if(verbose)
                {
                    j = 3;
                }
                filf[l] = argv[j];
                l++;
            }
        }

        wofil.open(filt, std::ios::app);
        wofil << std::endl;
        for(k = 0; k - argc != 0 && k - numfiles != 0; k++)
        {
            rofil.open(filf[k]);
            if(rofil)
            {
                wofil << rofil.rdbuf() << std::endl;
                rofil.close();
                if(verbose)
                {
                    std::cout << filf[k] << " successfully appended to" << filt << "." << std::endl;
                }
            }
        }
        wofil.close();
        std::cout << "Appending completed." << std::endl << std::endl;
        return 0;
    }

    while(std::getline(std::cin, filf[l]))
    {
        rofil.open(filf[l]);
        if(rofil)
        {
            wofil << rofil.rdbuf() << std::endl;
            rofil.close();
            if(verbose)
            {
                std::cout << filf[l] << " successfully appended to" << filt << "." << std::endl;
            }
        }
        l++;
    }
    wofil.close();
    std::cout << "Appending completed." << std::endl << std::endl;
    return 0;
}
