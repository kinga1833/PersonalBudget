#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
    public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string convertFloatToString(float amount);
    static float convertStringToFloat(string number);
    static float changeCommaForDot (string amount);

};
#endif
