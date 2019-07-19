#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Date.h"
#include "IncomesExpenses.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "Markup.h"

using namespace std;

class BudgetManager
{
    const int loggedInUserID;
    vector <IncomesExpenses> incomes;
    vector <IncomesExpenses> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    Date date;

    IncomesExpenses addInformationAboutIncome();
    IncomesExpenses addInformationAboutExpense();
    int getMonthFromIncomeDate (int incomeDate);
    int getYearFromIncomeDate( int incomeDate);
    vector <IncomesExpenses> loadIncomesOrExpensesFromChoosenPeriod (vector <IncomesExpenses> incomes, int dateFrom, int dateTo);
    int showIncomeOrExpenseBalance(vector <IncomesExpenses> simpleVector);
    void showVectorElements (vector <IncomesExpenses> simpleVector);
    float getTotalAmountFromChoosenPeriod (vector <IncomesExpenses> simpleVector);

    public:
        BudgetManager(string incomesFileName, string expensesFileName, int LOGGEDINUSERID)
        :incomesFile(incomesFileName), expensesFile(expensesFileName), loggedInUserID (LOGGEDINUSERID)
        {
            incomes = incomesFile.downloadLoggedInUserIncomes(loggedInUserID);
            expenses = expensesFile.downloadLoggedInUserExpenses(loggedInUserID);
        };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showBalanceFromChoosenPeriod();


};

#endif
