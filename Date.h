#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    int dayInt;
    int monthInt;
    int yearInt;
    string day;
    string month;
    string year;
    int date;

public:
    int currentDay();
    int currentMonth();
    int currentYear();
    int howManyDaysHasMonthHave (int month, int year);
    bool isTheYearALeapYear (int year);
    int todaysDate();
    int otherDate();
    bool isTheDateCorrect (string date);
    string showDate(int dateWithoutDash);
    int convertDateToDateWithoutDash(string dateInYyyyMmDdFormat);
    string convertToDateWithDash(int date);
};
#endif
