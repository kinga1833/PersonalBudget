#include "PersonalBudget.h"

void PersonalBudget::userRegister()
{
    userManager.userRegister();
}

void PersonalBudget:: showAllUsers()
{
    userManager.showAllUsers();
}
void PersonalBudget::logIn()
{
    userManager.logIn();
    if(userManager.checkIfUserIsLoggedIn())
    {
        budgetManager = new BudgetManager (incomesFileName, expensesFileName, userManager.getLoggedInUserID());
    }
}
int PersonalBudget::getLoggedInUserID()
{
    userManager.getLoggedInUserID();
}
void PersonalBudget::changePassword()
{
    userManager.changePassword();
}
void PersonalBudget::logOut()
{
    userManager.logOut();
    delete budgetManager;
    budgetManager = NULL;
}
void PersonalBudget::addIncome()
{
    if (userManager.checkIfUserIsLoggedIn())
    {
        budgetManager->addIncome();
    }
    else
    {
        cout << "If you want to add new income, you need to log in." << endl;
        system("pause");
    }
}
void PersonalBudget::addExpense()
{
    if (userManager.checkIfUserIsLoggedIn())
    {
        budgetManager->addExpense();
    }
    else
    {
        cout << "If you want to add new expense, you need to log in." << endl;
        system("pause");
    }
}
void PersonalBudget::showCurrentMonthBalance()
{
    if (userManager.checkIfUserIsLoggedIn())
    {
        budgetManager->showCurrentMonthBalance();
    }
    else
    {
        cout << "If you want to display current month balance, you need to log in." << endl;
        system("pause");
    }
}
void PersonalBudget::showLastMonthBalance()
{
    if (userManager.checkIfUserIsLoggedIn())
    {
        budgetManager->showLastMonthBalance();
    }
    else
    {
        cout << "If you want to display last month balance, you need to log in." << endl;
        system("pause");
    }
}
void PersonalBudget::showBalanceFromChoosenPeriod()
{
    if (userManager.checkIfUserIsLoggedIn())
    {
        budgetManager->showBalanceFromChoosenPeriod();
    }
    else
    {
        cout << "If you want to display balance from choosen period, you need to log in." << endl;
        system("pause");
    }
}
