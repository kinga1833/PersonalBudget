#include "Date.h"

int Date::currentDay()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    dayInt = st.wDay;
    return dayInt;
}
int Date::currentMonth()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    monthInt = st.wMonth;
    return monthInt;
}
int Date::currentYear()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    yearInt= st.wYear;
    return yearInt;
}

int Date::todaysDate()
{
    string dateString;
    day = AuxiliaryMethods::convertIntToString(currentDay());
    if (day.length() == 1)
    {
        day = "0" + day;
    }
    month = AuxiliaryMethods::convertIntToString(currentMonth());
    if (month.length() == 1)
    {
        month = "0" + month;
    }
    year = AuxiliaryMethods::convertIntToString(currentYear());

    dateString = year + month + day;

    date = AuxiliaryMethods::convertStringToInt(dateString);

    return date;
}
bool Date::isTheYearALeapYear (int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
int Date::otherDate()
{
    string dateString;
    string numbersDateFormat;
    do
    {
        dateString = "";
        cout << "Enter the date of getting income in yyyy-mm-dd format: ";
        cin >> dateString;
    }
    while (isTheDateCorrect(dateString) == false);

    for (int i=0; i< dateString.length(); i++)
    {
        if (dateString[i] != '-')
            numbersDateFormat += dateString[i] ;
    }
    date = AuxiliaryMethods::convertStringToInt(numbersDateFormat);

    return date;
}
bool Date::isTheDateCorrect (string date)
{
    year = "";
    month = "";
    day = "";
    for (int i=0; i<date.length(); i++)
    {
        if (i<=3)
            year += date[i];
        else if ((i>=5) & (i<=6))
            month += date[i];
        else if ((i>=8) & (i<=9))
            day += date[i];
    }
    int yearInteger = AuxiliaryMethods::convertStringToInt(year);
    int monthInteger = AuxiliaryMethods::convertStringToInt(month);
    int dayInteger = AuxiliaryMethods::convertStringToInt(day);

    if(( yearInteger < 2000) || (yearInteger > currentYear()))
    {
        cout << "Entered date is incorrect. Please enter the date between 2000-01-01 and the last day of current month." << endl;
        return false;
    }
    else if ((yearInteger < currentYear()) & ((monthInteger<1) || (monthInteger>12)))
    {
        cout << "Entered date is incorrect. Please enter the date between 2000-01-01 and the last day of current month." << endl;
        return false;
    }
    else if (dayInteger > howManyDaysHasMonthHave(monthInteger, yearInteger))
    {
        cout << "Entered date is incorrect. Please enter the date between 2000-01-01 and the last day of current month." << endl;
        return false;
    }
    else if ((yearInteger == currentYear()) & ( monthInteger > currentMonth()))
    {
        cout << "Entered date is incorrect. Please enter the date between 2000-01-01 and the last day of current month." << endl;
        return false;
    }
    else
    {
        return true;
    }
}
int Date::howManyDaysHasMonthHave (int month, int year)
{
    int numberOfDays;

    if((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
    {
        numberOfDays = 31;
    }
    else if ((month == 2) & (isTheYearALeapYear(year) == true))
    {
        numberOfDays = 29;
    }
    else if ((month == 2) & (isTheYearALeapYear(year) == false))
    {
        numberOfDays = 28;
    }
    else if ((month == 4) ||(month == 6) ||(month == 9) ||(month == 11))
    {
        numberOfDays = 28;
    }
    return numberOfDays;
}
string Date::showDate(int dateWithoutDash)
{
    string stringDateWithoutDast = AuxiliaryMethods::convertIntToString(dateWithoutDash);
    string dateFormat;

    for (int i=0; i< stringDateWithoutDast.length(); i++)
    {
        dateFormat+=stringDateWithoutDast[i];
        if((i==3) || (i==5))
            dateFormat += '-';
    }
    return dateFormat;
}
int Date::convertDateToDateWithoutDash(string dateInYyyyMmDdFormat)
{
    string dateWithoutDashString;
    int dateWithoutDash;

    for (int i=0; i<dateInYyyyMmDdFormat.length(); i++)
    {
        if (dateInYyyyMmDdFormat[i] != '-')
            dateWithoutDashString+=dateInYyyyMmDdFormat[i];
    }
    dateWithoutDash = AuxiliaryMethods::convertStringToInt(dateWithoutDashString);

    return dateWithoutDash;
}
