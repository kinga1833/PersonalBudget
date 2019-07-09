#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "IncomesExpenses.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class IncomesFile
{
    const string incomesFileName;
    int lastIncomeID;

    bool fileExists (const string& fileName);

public:
    IncomesFile(string INCOMESFILENAME):
    incomesFileName(INCOMESFILENAME) {
    lastIncomeID = 0;
    }
    vector <IncomesExpenses> downloadLoggedInUserIncomes(int loggedInUserID);
    void addIncomeToFile(IncomesExpenses income);
    int downloadLastIncomeID();
};

#endif
