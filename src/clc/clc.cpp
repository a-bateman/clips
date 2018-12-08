//clc v1
//Calculate program for CLI.
//Written by: Andrew B.
//Originally written: 11-28-18
//Licensed under the LOLicense. It is expected that you have read the LOL.txt file included with this source code before modifying, compiling or distributing it.
//TODO: Allow input through CLI arguments.

#include <stdio.h>
#include <string>
#include <commander.hpp>
#include <exception>

inline bool shouldDisplayHelp (const CMD::commander &args) {
    return(args.isFlagSet("help") || args.isFlagSet("info"));

}

inline bool helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args)) {
        std::cout << "\n\nclc v1 Info:\n"
                  << "\nReleased under LOL License.  Please see the lol.txt file for details.\n"
                  << "clc is designed to complete simple calculations.\n"
                  << "You may call clc on it's own and input mathmatical expression to be calculated at run time.\n"
                  << "Yoy may also call clc with the mathmatical expression to be calculated as arguments with a space between each part of the expression.\n"
                  << "EXAMPLE: ./clc 1 + 1\n"
                  << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n";
        return true;
    }
    return false;
};

inline void inputExpression(int& fnum, int& snum, std::string& oper) {
    std::cout << "What is the mathmatical expression you would like to calculate? (Each part must be seperated by spaces) ";
    std::cin >> fnum >> oper >> snum;
}

inline int calc ( int& fnum, int& snum, std::string& oper) {
    if(oper == "+")
    {
        return fnum+snum;
    }
    if(oper == "-")
    {
        return fnum-snum;
    }
    if(oper == "*" || oper == "x" || oper == "X")
    {
        return fnum*snum;
    }
    if(oper == "/" || oper == ""\"" || oper == "÷")
    {
        return fnum/snum;
    }
    if(oper == "^")
    {
        int result = fnum;
        while(; snum != 0; snum--)
        {
            result = result * fnum;
        }
        return result;
    }
    else
    {
        std::cout << oper << " is not a valid mathmatical operator." << std::endl;
        std::cout << "Accepted mathmatical operators are:" << std::endl;
        std::cout << "Addition: +" << std::endl;
        std::cout << "Subtraction: -" << std::endl;
        std::cout << "Multiplication: *, x, X" << std::endl;
        std::cout << "Division: /, \, ÷" << std::endl;
    }
}


int main(int argc, char** argv)
{
    CMD::commander args (argc-1, argv + 1);
    std::string oper;
    int fnum, snum;

    if(helpMessage(args))
        return 0;

    if(args.getFlagCount() < 1)
        inputExpression();
    else
        filf = args.getAllFlagsUnlike(std::regex ("-\\w*"))[0];

    cout << "Answer is: " << calc(fnum, snum, oper) << std::endl;
    return 0;
}
