#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    IncomesExpenses income;

    system("cls");
    cout << " >>> ADD INCOME <<<" << endl << endl;
    income = addInformationAboutIncome();

    expenses.push_back(income);
    incomesFile.addIncomeToFile(income);
}
IncomesExpenses BudgetManager::addInformationAboutIncome()
{
    IncomesExpenses income;
    char choice;
    int dateIncome;
    string title, amount;

    income.setIncomeOrExpenseID(incomesFile.downloadLastIncomeID()+ 1);
    income.setUserID(loggedInUserID);

    cout << " If you want to add income from today, please press 't'. If you want to add income from other date, please press 'o'." << endl;
    cin >> choice;

    if (choice == 't')
        dateIncome = date.todaysDate();

    else if (choice == 'o')
        dateIncome = date.otherDate();

    cout << "Enter income's title: ";
    cin >> title;

    cout << "Enter income's amount: ";
    cin >> amount;

    income.setDate(dateIncome);
    income.setTitle(title);
    income.setAmount(atof(amount.c_str()));

    return income;
}
void BudgetManager::addExpense()
{
    IncomesExpenses expense;

    system("cls");
    cout << " >>> ADD EXPENSE <<<" << endl << endl;
    expense = addInformationAboutExpense();

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);
}
IncomesExpenses BudgetManager::addInformationAboutExpense()
{
    IncomesExpenses expense;
    char choice;
    int dateExpense;
    string title, amount;

    expense.setIncomeOrExpenseID(expensesFile.downloadLastExpenseID()+ 1);
    expense.setUserID(loggedInUserID);

    cout << " If you want to add expense from today, please press 't'. If you want to add expense from other date, please press 'o'." << endl;
    cin >> choice;

    if (choice == 't')
        dateExpense = date.todaysDate();

    else if (choice == 'o')
        dateExpense = date.otherDate();

    cout << "Enter expense's title: ";
    cin >> title;

    cout << "Enter expense's amount: ";
    cin >> amount;

    expense.setDate(dateExpense);
    expense.setTitle(title);
    expense.setAmount(atof(amount.c_str()));

    return expense;
}
vector <IncomesExpenses> BudgetManager::loadIncomesOrExpensesFromChoosenPeriod (vector <IncomesExpenses> incomes, int dateFrom, int dateTo)
{
    int justDate;
    IncomesExpenses incomeOrExpenseFromChoosenPeriod;
    vector <IncomesExpenses>incomesOrExpensesFromChoosenPeriod;

    for (int i= 0; i<incomes.size(); i++)
    {
        justDate = incomes[i].getDate();

        if ((justDate>= dateFrom) & (justDate<=dateTo))
        {
            incomeOrExpenseFromChoosenPeriod.setIncomeOrExpenseID(incomes[i].getIncomeOrExpenseID());
            incomeOrExpenseFromChoosenPeriod.setDate(incomes[i].getDate());
            incomeOrExpenseFromChoosenPeriod.setTitle(incomes[i].getTitle());
            incomeOrExpenseFromChoosenPeriod.setAmount(incomes[i].getAmount());
            incomesOrExpensesFromChoosenPeriod.push_back(incomeOrExpenseFromChoosenPeriod);
        }
    }
    return incomesOrExpensesFromChoosenPeriod;
}
int BudgetManager::getTotalAmountFromChoosenPeriod (vector <IncomesExpenses> simpleVector )
{
    int totalAmount = 0;
    for (int i=0; i< simpleVector.size(); i++)
    {
        totalAmount+=simpleVector[i].getAmount();
    }
    return totalAmount;
}
void BudgetManager::showVectorElements (vector <IncomesExpenses> simpleVector)
{
    for (int i=0; i<simpleVector.size(); i++)
    {
        cout <<endl;
        cout << "Date: " << date.showDate(simpleVector[i].getDate()) << endl;
        cout << "Title: " << simpleVector[i].getTitle() << endl;
        cout << "Amount: " << simpleVector[i].getAmount() << endl;
    }
}
void BudgetManager::showCurrentMonthBalance ()
{
    string monthString = AuxiliaryMethods::convertIntToString(date.currentMonth());
    if (monthString.length() == 1)
        monthString = "0"+monthString;

    string dateFrom = AuxiliaryMethods::convertIntToString(date.currentYear())+monthString+"01";
    string dateTo = AuxiliaryMethods::convertIntToString(date.currentYear())+ monthString+AuxiliaryMethods::convertIntToString(date.howManyDaysHasMonthHave(date.currentMonth(), date.currentYear()));
    int dateFromInt = AuxiliaryMethods::convertStringToInt(dateFrom);
    int dateToInt = AuxiliaryMethods::convertStringToInt(dateTo);
    vector <IncomesExpenses> incomesFromCurrentMonth = loadIncomesOrExpensesFromChoosenPeriod (incomes, dateFromInt, dateToInt);
    vector <IncomesExpenses> expensesFromCurrentMonth = loadIncomesOrExpensesFromChoosenPeriod (expenses, dateFromInt, dateToInt);

    cout << " <<<  CURRENT MONTH BALANCE:  >>>" << endl << endl << endl;
    cout << "***  INCOMES:  ***" << endl;
    sort (incomesFromCurrentMonth.begin(), incomesFromCurrentMonth.end());
    showVectorElements(incomesFromCurrentMonth);
    cout << endl << "Incomes total amount: " << getTotalAmountFromChoosenPeriod(incomesFromCurrentMonth) << endl << endl;

    cout << endl <<"***  EXPENSES:  ***" << endl;
    sort (expensesFromCurrentMonth.begin(), expensesFromCurrentMonth.end());
    showVectorElements(expensesFromCurrentMonth);
    cout << endl << "Expenses total amount: " << getTotalAmountFromChoosenPeriod(expensesFromCurrentMonth) << endl << endl;

    cout << "Difference beetwen incomes and expeses: " << getTotalAmountFromChoosenPeriod(incomesFromCurrentMonth) - getTotalAmountFromChoosenPeriod(expensesFromCurrentMonth) << endl << endl;
}
void BudgetManager::showLastMonthBalance ()
{
    string monthString = AuxiliaryMethods::convertIntToString(date.currentMonth()-1);
    if (monthString.length() == 1)
        monthString = "0"+ monthString;
    int year = date.currentYear();
    if (monthString == "01")
        year = year-1;

    string dateFrom = AuxiliaryMethods::convertIntToString(year)+monthString+"01";
    string dateTo = AuxiliaryMethods::convertIntToString(year)+ monthString+AuxiliaryMethods::convertIntToString(date.howManyDaysHasMonthHave(date.currentMonth()-1, date.currentYear()));
    int dateFromInt = AuxiliaryMethods::convertStringToInt(dateFrom);
    int dateToInt = AuxiliaryMethods::convertStringToInt(dateTo);
    vector <IncomesExpenses> incomesFromLastMonth = loadIncomesOrExpensesFromChoosenPeriod (incomes, dateFromInt, dateToInt);
    vector <IncomesExpenses> expensesFromLastMonth = loadIncomesOrExpensesFromChoosenPeriod (expenses, dateFromInt, dateToInt);

    cout << " <<<  LAST MONTH BALANCE:  >>>" << endl << endl;
    cout << "***  INCOMES:  ***" << endl;
    sort (incomesFromLastMonth.begin(), incomesFromLastMonth.end());
    showVectorElements(incomesFromLastMonth);
    cout << endl << "Incomes total amount: " << getTotalAmountFromChoosenPeriod(incomesFromLastMonth) << endl << endl;

    cout << "***  EXPENSES:  ***" << endl;
    sort (expensesFromLastMonth.begin(), expensesFromLastMonth.end());
    showVectorElements(expensesFromLastMonth);
    cout << endl << "Expenses total amount: " << getTotalAmountFromChoosenPeriod(expensesFromLastMonth) << endl << endl << endl;

    cout << "Difference beetwen incomes and expeses: " << getTotalAmountFromChoosenPeriod(incomesFromLastMonth) - getTotalAmountFromChoosenPeriod(expensesFromLastMonth) << endl << endl;

}
void BudgetManager::showBalanceFromChoosenPeriod()
{
    int dateFrom, dateTo;
    string dateFromString, dateToString;

    cout << " <<<  CHOOSEN PERIOD BALANCE:  >>>" << endl << endl;
    cout << "Provide the date since you want to display the balance in yyyy-mm-dd format. " << endl;
    cout << "From: ";
    cin >> dateFromString;
    cout << "To: ";
    cin >> dateToString;

    dateFrom = date.convertDateToDateWithoutDash(dateFromString);
    dateTo = date.convertDateToDateWithoutDash(dateToString);
    vector <IncomesExpenses> incomesFromChoosenPeriod = loadIncomesOrExpensesFromChoosenPeriod (incomes, dateFrom, dateTo);
    vector <IncomesExpenses> expensesFromChoosenPeriod = loadIncomesOrExpensesFromChoosenPeriod (expenses, dateFrom, dateTo);

    cout << " <<<  CHOOSEN PERIOD BALANCE:  >>>" << endl << endl;
    cout << "***  INCOMES:  ***" << endl;
    sort (incomesFromChoosenPeriod.begin(), incomesFromChoosenPeriod.end());
    showVectorElements(incomesFromChoosenPeriod);
    cout << endl << "Incomes total amount: " << getTotalAmountFromChoosenPeriod(incomesFromChoosenPeriod) << endl << endl;

    cout << "***  EXPENSES:  ***" << endl;
    sort (expensesFromChoosenPeriod.begin(), expensesFromChoosenPeriod.end());
    showVectorElements(expensesFromChoosenPeriod);
    cout << endl << "Expenses total amount: " << getTotalAmountFromChoosenPeriod(expensesFromChoosenPeriod) << endl << endl << endl;

    cout << "Difference beetwen incomes and expeses: " << getTotalAmountFromChoosenPeriod(incomesFromChoosenPeriod) - getTotalAmountFromChoosenPeriod(expensesFromChoosenPeriod) << endl << endl;
}
