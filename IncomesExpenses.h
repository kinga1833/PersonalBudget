#ifndef INCOMESEXPENSES_H
#define INCOMESEXPENSES_H

#include <iostream>

using namespace std;

class IncomesExpenses
{
    int userID;
    int incomeOrExpenseID;
    int date;
    string title;
    float amount;

public:
    void setUserID (int newUserID);
    void setIncomeOrExpenseID (int newID);
    void setDate(int newDate);
    void setTitle (string newTitle);
    void setAmount (float newAmount);

    int getUserID();
    int getIncomeOrExpenseID();
    int getDate();
    string getTitle();
    float getAmount();
    bool operator < (const IncomesExpenses &x)const;
};

#endif
