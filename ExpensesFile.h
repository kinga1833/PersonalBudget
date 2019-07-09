#ifndef EXPENSESFILE_H
#define EXPENSESSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "IncomesExpenses.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class ExpensesFile
{
    const string expensesFileName;
    int lastExpenseID;
    bool fileExists (const string& fileName);

public:
    ExpensesFile(string EXPENSESFILENAME):
    expensesFileName(EXPENSESFILENAME) {
    lastExpenseID = 0;
    };
    vector <IncomesExpenses> downloadLoggedInUserExpenses(int loggedInUserID);
    void addExpenseToFile(IncomesExpenses income);
    int downloadLastExpenseID();
};

#endif
