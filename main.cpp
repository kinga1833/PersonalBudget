#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget ("users.xml", "incomes.xml", "expenses.xml");

    cout << "<<<< PERSONAL BUDGET >>>> " << endl << endl;
    cout << " ** Menu ** " << endl << endl;
    cout << "1. User register " << endl;
    cout << "2. Log In " << endl;
    cout << "3. Exit " << endl;

    char choice;
    while (true)
    {
        if (personalBudget.getLoggedInUserID() == 0)
        {
            cin >> choice;
            switch (choice)
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
            system ("cls");
            cout << " ** User menu ** " << endl << endl;
            cout << "1. Add income " << endl;
            cout << "2. Add expense " << endl;
            cout << "3. Show current month balance " << endl;
            cout << "4. Show last month balance " << endl;
            cout << "6. Show balance from choosen period " << endl;
            cout << "7. Change password " << endl;
            cout << "8. Log out" << endl;

            cin >> choice;
            switch (choice)
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
