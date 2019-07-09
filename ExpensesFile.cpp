#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(IncomesExpenses expense)
{
    CMarkup xml;

    if (fileExists(expensesFileName.c_str()) == false)
    {
        xml.AddElem( "EXPENSES" );
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "USERID", expense.getUserID());
        xml.AddElem( "EXPENSEID", expense.getIncomeOrExpenseID());
        xml.AddElem( "DATE", expense.getDate());
        xml.AddElem( "TITLE", expense.getTitle());
        xml.AddElem( "AMOUNT", expense.getAmount());
        xml.OutOfElem();
        xml.Save( expensesFileName.c_str() );
    }
    else
    {
        xml.Load(expensesFileName.c_str());
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "USERID", expense.getUserID());
        xml.AddElem( "EXPENSEID", expense.getIncomeOrExpenseID());
        xml.AddElem( "DATE", expense.getDate());
        xml.AddElem( "TITLE", expense.getTitle());
        xml.AddElem( "AMOUNT", expense.getAmount());
        xml.OutOfElem();
        xml.Save( expensesFileName.c_str() );
    }
    lastExpenseID++;

    system("pause");
}
vector <IncomesExpenses> ExpensesFile::downloadLoggedInUserExpenses(int loggedInUserID)
{
    CMarkup xml;
    IncomesExpenses expense;
    vector <IncomesExpenses> expenses;
    int userid;

    xml.Load(expensesFileName.c_str());
    xml.FindElem("EXPENSES");
    xml.IntoElem();

    while (xml.FindElem("EXPENSE"))
    {
        xml.IntoElem();
        xml.FindElem("USERID");
        userid = atoi( MCD_2PCSZ(xml.GetData()));

        if (userid == loggedInUserID)
        {
            expense.setUserID(userid);
            xml.FindElem( "EXPENSEID" );
            expense.setIncomeOrExpenseID(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "DATE" );
            expense.setDate(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "TITLE" );
            expense.setTitle(MCD_2PCSZ(xml.GetData())) ;
            xml.FindElem( "AMOUNT" );
            expense.setAmount(atoi (MCD_2PCSZ(xml.GetData())));

            expenses.push_back(expense);
        }
         xml.OutOfElem();
    }
    lastExpenseID = expenses.back().getIncomeOrExpenseID();

    return expenses;
}
bool ExpensesFile::fileExists (const string& fileName)
{
    fstream plik;
    plik.open(fileName.c_str(), ios::in);
    if ( plik.is_open() )
    {
        plik.close();
        return true;
    }
    plik.close();
    return false;
}
int ExpensesFile::downloadLastExpenseID()
{
    return lastExpenseID;
}
