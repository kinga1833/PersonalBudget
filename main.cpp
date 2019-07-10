#include <iostream>
#include <windows.h>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget ("users.xml", "incomes.xml", "expenses.xml");

    char choiceFromMainManu, choiceFromUserMenu;
    while (true)
    {
        if (personalBudget.getLoggedInUserID() == 0)
        {
            choiceFromMainManu = personalBudget.chooseOptionFromMenu();
            switch (choiceFromMainManu)
            {
            case'1':
                    personalBudget.userRegister();
                break;
            case '2':
                personalBudget.logIn();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << "There is no option on the menu." << endl;
            }
        }
        else
        {
            choiceFromUserMenu = personalBudget.chooseOptionFromMenuLoggedUsers();
            switch (choiceFromUserMenu)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showCurrentMonthBalance();
                break;
            case '4':
                personalBudget.showLastMonthBalance();
                break;
            case '5':
                personalBudget.showBalanceFromChoosenPeriod();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logOut();
                break;
            }
        }
    }
    return 0;
}
