#include <iostream>
#include <windows.h>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string incomesFileName;
    const string expensesFileName;

public:
    PersonalBudget(string usersFileName, string INCOMESFILENAME, string EXPENSESFILENAME)
    :userManager(usersFileName), incomesFileName(INCOMESFILENAME),expensesFileName(EXPENSESFILENAME)
    {
        budgetManager = NULL;
    };
    ~PersonalBudget()
    {
        //delete budgetManager;
        budgetManager = NULL;
    };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showBalanceFromChoosenPeriod();
    void userRegister();
    void showAllUsers();
    void logIn();
    int getLoggedInUserID();
    void changePassword();
    void logOut();
    void displayMenu();
    char chooseOptionFromMenu();
    char chooseOptionFromMenuLoggedUsers();

};
