//sfa v1
//Simple File Appender program for CLI.
//Written by: Andrew B.
//Originally written: 11-20-18
//Licensed under the BSD 3 clause license. It is expected that you have read the license file included with this source code before modifying, compiling or distributing it.
//Special thanks to Maxi for commander.hpp (https://github.com/Wittmaxi/).
//WIP: Allow use of piped data as an input.

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <commander.hpp>


inline bool shouldDisplayHelp (const CMD::commander &args) {
    return(args.isFlagSet("help") || args.isFlagSet("info"));
}

inline bool helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args))
    std::cout << "\n\nsfa v1 Info:\n"
              << "\n\nPlanned to be released out of house with the name SFA (Simple File Appender) under LOL License\n"
              << "***Highly Experimental: Not For Production Use!***\n"
              << "sfa is designed to append an unlimited number of files into a single specified file.\n"
              << "You may pipe input from either a file or another program.  Expected format is as follows: \n"
              << "For piping data from a file: One file per line with the first in the list being the file appended to.\n"
              << "For piping data from a CLI program: One file per stdin with the first in the list being the file appended to.\n"
              << "You may call sfa on it's own and input the number of files during runtime.\n"
              << "You may also call sfa using the file names as arguments.\n"
              << "EXAMPLE: ./sfa ./file-appended-to ./first-file-appended-from ./second-file-appended-from ./etc..\n\n\n"
              << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n\n";
    else
        return false;
    return true;
};

struct vout_t {
    bool verbose = false;
} vout;

vout_t operator<< (vout_t& os, std::string input) {
    if (os.verbose)
        std::cout << input;
    return os;
}

int main(int argc, char** argv)
{
    CMD::commander args (argc, argv);
    bool verbose; //TODO make code independent of this variable
    int i, j, k, l = 0, numfiles;
    std::string filf[i], filt, line;
    std::ifstream rofil;
    std::ofstream wofil;

    if(argc > 1)
    {
        if(helpMessage(args))
            return 0;
        if(args.isFlagSet("v"))
        {
            vout.verbose = verbose = true;
            vout << "Verbose mode enabled.\n";
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
