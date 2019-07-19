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
float AuxiliaryMethods::convertStringToFloat(string number)
{
    float numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}
float AuxiliaryMethods::changeCommaForDot (string amount)
{
    float correctAmount = 0;
    string correctAmountString = "";

    for (int i=0; i<amount.length(); i++)
    {
        if (amount[i] == ',')
            correctAmountString+= '.';
        else
            correctAmountString += amount[i];
    }
    correctAmount = convertStringToFloat(correctAmountString);
    return correctAmount;
}
