//cal v1
//Calendar program for CLI.
//Written by: Andrew B.
//Originally written: 12-8-18
//Licensed under the LOLicense. It is expected that you have read the LOL.txt file included with this source code before modifying, compiling or distributing it.

#include <stdio.h>
#include <string>
#include <commander.hpp>
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
        std::cout << "\n\ncal v1 Info:\n"
                  << "\nReleased under LOL License.  Please see the lol.txt file for details.\n"
                  << "cal is designed to print a simple calendar to the screen.\n"
                  << "You may call cal on it's own to display a calendar of the current month.\n"
                  << "Yoy may also call cal with a month and year to display the calendar of that month for that specific year.\n"
                  << "EXAMPLE: ./cal November 1988"
                  << "CAUTION: Just as with any action on a computer it is important that you THINK BEFORE YOU TYPE. Especially if running as root.\n";
        return true;
    }
    return false;
};

inline void displayCal (int& day, std::string& smonth, int& year)
{
    std::cout << day << "/" << smonth << "/" << year << "\n"

};

inline void setimonth (std::string& smonth, int& imonth)
{
    if(smonth == "January" || smonth = "january")
        iday = 1;
    if(smonth == "February" || smonth = "february")
        iday = 2;
    if(smonth == "March" || smonth = "march")
        iday = 3;
    if(smonth == "April" || smonth = "april")
        iday = 4;
    if(smonth == "May" || smonth = "may")
        iday = 5;
    if(smonth == "June" || smonth = "june")
        iday = 6;
    if(smonth == "July" || smonth = "july")
        iday = 7;
    if(smonth == "August" || smonth = "august")
        iday = 8;
    if(smonth == "September" || smonth = "september")
        iday = 9;
    if(smonth == "October" || smonth = "october")
        iday = 10;
    if(smonth == "November" || smonth = "november")
        iday = 11;
    if(smonth == "December" || smonth = "december")
        iday = 12;
    else
    {
        std::cout << "Invalid month\n";
        exit();
    }
};

inline void setsmonth(std::string &month, int &year)
{

};

inline void getCurrDate(int &day, int &month, int &year)
{

};

int main(int argc, char** argv)
{
    CMD::commander args (argc-1, argv + 1);
    std::string *smonth = "XXXX";
    int *iday = 0, *imonth = 0, *iyear = 0;

    if(helpMessage(args))
        return 0;

    if(args.getFlagCount() < 1)
        inputExpression();
    else
        filf = args.getAllFlagsUnlike(std::regex ("-\\w*"))[0];
    if(&smonth != "XXXX")
    {
        setimonth(smonth, imonth);
    }
    if(&smonth == "XXXX")
    {
        setsmonth(smonth, imonth);
    }
    getCurrDate(iday, imonth, iyear);
    displayCal(iday, imonth, iyear);

}
