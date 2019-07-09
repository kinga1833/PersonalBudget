#include "IncomesExpenses.h"

void IncomesExpenses::setUserID (int newUserID)
{
    if (newUserID >=0)
        userID = newUserID;
}
void IncomesExpenses::setIncomeOrExpenseID (int newID)
{
    if (newID >= 0)
        incomeOrExpenseID = newID;
}
void IncomesExpenses::setDate (int newDate)
{
    if (newDate >= 20000101)
        date = newDate;
}
void IncomesExpenses::setTitle (string newTitle)
{
    title = newTitle;
}
void IncomesExpenses::setAmount (float newAmount)
{
    amount = newAmount;
}
int IncomesExpenses::getUserID()
{
    return userID;
}
int IncomesExpenses::getIncomeOrExpenseID()
{
    return incomeOrExpenseID;
}
int IncomesExpenses::getDate()
{
    return date;
}
string IncomesExpenses::getTitle()
{
    return title;
}
float IncomesExpenses::getAmount()
{
    return amount;
}
bool IncomesExpenses::operator < (const IncomesExpenses &x)const
{
    return date<x.date;
}
