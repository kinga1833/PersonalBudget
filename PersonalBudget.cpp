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
char PersonalBudget::chooseOptionFromMenu()
{
    char choice;
    system ("cls");
    cout << "<<<< PERSONAL BUDGET >>>> " << endl << endl;
    cout << " ** Menu ** " << endl << endl;
    cout << "1. User register " << endl;
    cout << "2. Log In " << endl;
    cout << "3. Exit " << endl << endl;
    cout << "Choose option from menu: ";
    cin >> choice;
    cout << endl;
    return choice;
}
char PersonalBudget::chooseOptionFromMenuLoggedUsers()
{
    system ("cls");
    char choice;

    cout << " ** User menu ** " << endl << endl;
    cout << "1. Add income " << endl;
    cout << "2. Add expense " << endl;
    cout << "3. Show current month balance " << endl;
    cout << "4. Show last month balance " << endl;
    cout << "6. Show balance from choosen period " << endl;
    cout << "7. Change password " << endl;
    cout << "8. Log out" << endl;

    cout << "Choose option from menu: ";
    cin >> choice;

    return choice;
}

