//smn v1
//Repeats a phrase until killed for CLI.
//Written by: Andrew B.
//Originally written: 11-28-18
//Licensed under the LOLicense.  It is expected that you have read the LOL-pfc.txt file included with this source code before modifying, compiling or distributing it.

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <commander.hpp>

inline bool shouldDisplayHelp (const CMD::commander &args) {
    return(args.isFlagSet("help") || args.isFlagSet("info"));
}

inline bool helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args))
        std::cout << "\n\t\t\tcpf v1 Info: \n"
                << "\nReleased under LOL License.  Please see the lol.txt file for details.\n\n\n"
                << "smn is designed to repeat a phrase until killed using ctl-c.\n"
                << "You may call smn with the phrase to be repeated as arguments.\n"
                << "You may call smn on it's own and input the phrase to be repeated during runtime.\n"
                << "EXAMPLE: ./smn My phrase\n"
                << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n\n";
    else
        return false;
    return true;
};

inline std::string inputPhrase ()
{
    std::string phrase;
    std::cout << ">";
    std::cin >> phrase;
    return phrase;
}

int main(int argc, char** argv)
{
    CMD::commander args(argc-1, argv+1);
    std::string phrase;

    if (args.getFlagCount() == 1 && helpMessage(args))
        return 0;
    else if(args.getFlagCount() == 0)
        phrase = inputPhrase();
    else 
        phrase = args[0];

    while (true)
        std::cout << phrase << "\n";
    return 0;
}
