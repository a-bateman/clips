//cpf v1
//Print File Contents program for CLI.
//Written by: Andrew B.
//Originally written: 11-26-18
//Licensed under the LOLicense.  It is expected that you have read the LOL-pfc.txt file included with this source code before modifying, compiling or distributing it.

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <commander.hpp>

bool shouldDisplayHelp (const CMD::commander &args) {
    return(args.isFlagSet("help") || args.isFlagSet("info"));

}
void helpMessage(const CMD::commander &args)
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

void inputFileNames (std::string& filf, std::string& filt) {
        std::cout << "What file would you like to copy the contents of? ";
        std::cin >> filf;
        std::cout << "Where would you like the file contents to copied to? ";
        std::cin >> filt;
}

int copyFile (const std::string& filf, const std::string& filt) {
    std::ifstream rofil;
    std::ofstream wofil;
    
    rofil.open(filf);
    if(!rofil)
    {
        std::cout << "File to be copied does not exist!\n";
        return -1;
    }
    wofil.open(filt);
    wofil << rofil.rdbuf();
    rofil.close();
    wofil.close();
    return 0;
}

int main(int argc, char** argv)
{
    CMD::commander args(argc, argv);
    std::string filf, filt;

    if (args.getFlagCount() == 2)
        helpMessage(args);
    else if(args.getFlagCount() == 1)
        inputFileNames (filf, filt);
    else
    {
        filf = args[1];
        filt = args[2];
    }
    return copyFile (filf, filt);
}
