#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    IncomesExpenses income;

    system("cls");
    cout << " >>> ADD INCOME <<<" << endl << endl;
    income = addInformationAboutIncome();
    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);
    system("pause");
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
    income.setAmount(AuxiliaryMethods::changeCommaForDot(amount));
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
    expense.setAmount(AuxiliaryMethods::changeCommaForDot(amount));

    return expense;
}
vector <IncomesExpenses> BudgetManager::loadIncomesOrExpensesFromChoosenPeriod (vector <IncomesExpenses> incomes, int dateFrom, int dateTo)
{
    int justDate;
    Date dateDate;
    IncomesExpenses incomeOrExpenseFromChoosenPeriod;
    vector <IncomesExpenses>incomesOrExpensesFromChoosenPeriod;
    for (vector <IncomesExpenses> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        justDate = itr->getDate();

        if ((justDate>= dateFrom) & (justDate<=dateTo))
        {
            incomeOrExpenseFromChoosenPeriod.setIncomeOrExpenseID(itr->getIncomeOrExpenseID());
            incomeOrExpenseFromChoosenPeriod.setDate(itr->getDate());
            incomeOrExpenseFromChoosenPeriod.setTitle(itr->getTitle());
            incomeOrExpenseFromChoosenPeriod.setAmount(itr->getAmount());
            incomesOrExpensesFromChoosenPeriod.push_back(incomeOrExpenseFromChoosenPeriod);
        }
    }
    return incomesOrExpensesFromChoosenPeriod;
}
float BudgetManager::getTotalAmountFromChoosenPeriod (vector <IncomesExpenses> simpleVector )
{
    float totalAmount;
    for (vector <IncomesExpenses> :: iterator itr = simpleVector.begin(); itr != simpleVector.end(); itr++)
    {
        totalAmount+=itr->getAmount();
    }
    return totalAmount;
}
void BudgetManager::showVectorElements (vector <IncomesExpenses> simpleVector)
{
    for (vector <IncomesExpenses> :: iterator itr = simpleVector.begin(); itr != simpleVector.end(); itr++)
    {
        cout <<endl;
        cout << "Date: " << date.convertToDateWithDash(itr->getDate()) << endl;
        cout << "Title: " << itr->getTitle() << endl;
        cout << "Amount: " << itr->getAmount() << endl;
    }
}
void BudgetManager::showCurrentMonthBalance ()
{
    Date date;
    string monthString = AuxiliaryMethods::convertIntToString(date.currentMonth());
    if (monthString.length() == 1)
        monthString = "0"+monthString;

    string dateFrom = AuxiliaryMethods::convertIntToString(date.currentYear())+monthString+"01";
    string dateTo = AuxiliaryMethods::convertIntToString(date.currentYear())+ monthString+AuxiliaryMethods::convertIntToString(date.howManyDaysHasMonthHave(date.currentMonth(), date.currentYear()));
    int dateFromInt = AuxiliaryMethods::convertStringToInt(dateFrom);
    int dateToInt = AuxiliaryMethods::convertStringToInt(dateTo);
    vector <IncomesExpenses> incomesFromCurrentMonth = loadIncomesOrExpensesFromChoosenPeriod (incomes, dateFromInt, dateToInt);
    vector <IncomesExpenses> expensesFromCurrentMonth = loadIncomesOrExpensesFromChoosenPeriod (expenses, dateFromInt, dateToInt);
    system ("cls");
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
    system("pause");
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
    system ("cls");
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
    system("pause");

}
void BudgetManager::showBalanceFromChoosenPeriod()
{
    Date correctDate;
    int dateFrom, dateTo;
    string dateFromString, dateToString;
    system ("cls");
    cout << " <<<  CHOOSEN PERIOD BALANCE:  >>>" << endl << endl;
    cout << "Provide the date since you want to display the balance in yyyy-mm-dd format: " << endl;
    do
    {
        dateFromString = "";
        cin >> dateFromString;
    }
    while (correctDate.isTheDateCorrect(dateFromString) == false);

    cout << "Provide the date until you want to display the balance in yyyy-mm-dd format: " << endl;
    do
    {
        dateToString = "";
        cin >> dateToString;
    }
    while (correctDate.isTheDateCorrect(dateToString) == false);

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
    system("pause");
}
