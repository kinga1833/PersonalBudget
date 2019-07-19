#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}
string AuxiliaryMethods::convertFloatToString(float amount)
{
    ostringstream ss;
    ss << amount;
    string amountString=ss.str();
    return amountString;
}
