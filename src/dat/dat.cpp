//dat v1
//Date and Time program for CLI.
//Written by: Andrew B.
//Originally written: 12-8-18
//Licensed under the BSD 3 clause license. It is expected that you have read the license file included with this source code before modifying, compiling or distributing it.

#include <stdio.h>
#include <string>
#include "/usr/local/include/commander.hpp"
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>

inline bool shouldDisplayHelp (const CMD::commander &args) {
    return(args.isFlagSet("help") || args.isFlagSet("info"));

}

inline bool helpMessage(const CMD::commander &args)
{
    if (shouldDisplayHelp(args)) {
        std::cout << "\n\ndat v1 Info:\n"
                  << "\nReleased under BSD 3 clause license.  Please see the license file for details.\n"
                  << "dat is designed to print the current date and time to the screen.\n"
                  << "You call dat on it's own to display the current date and time.\n"
                  << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n";
        return true;
    }
    return false;
}

inline void displayDat(int day, std::string smonth, int year)
{
    std::cout << smonth << " " << day << ", " << year << "\n";
}

inline std::string setsmonth(int imonth)
{
    std::string smonth;
    if(imonth == 1)
        smonth = "January";
    if(imonth ==2 )
        smonth = "February";
    if(imonth == 3)
        smonth = "March";
    if(imonth == 4)
        smonth = "April";
    if(imonth == 5)
        smonth = "May";
    if(imonth == 6)
        smonth = "June";
    if(imonth == 7)
        smonth = "July";
    if(imonth == 8)
        smonth = "August";
    if(imonth == 9)
        smonth = "September";
    if(imonth == 10)
        smonth = "October";
    if(imonth == 11)
        smonth = "November";
    if(imonth == 12)
        smonth = "December";

    return smonth;
}

inline void getCurrDat(int &day, int &month, int &year, int &hour, int &minute, int &second)
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    month = (timePtr->tm_mon)+1;
    day = (timePtr->tm_mday);
    year = (timePtr->tm_year)+1900;
    hour = (timePtr->tm_hour);
    minute = (timePtr->tm_min);
    second = (timePtr->tm_sec);
}


int main(int argc, char** argv)
{
    CMD::commander args (argc-1, argv + 1);
    int iday, imonth, iyear, hour, minute, second;
    std::string smonth = "XXXX";

    getCurrDat(iday, imonth, iyear, hour, minute, second);
    if(smonth == "XXXX")
    {
        smonth = setsmonth(imonth);
    }

    if(helpMessage(args))
        return 0;

    displayDat(iday, smonth, iyear);
    return 0;
}
