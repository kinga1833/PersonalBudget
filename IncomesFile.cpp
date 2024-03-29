#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(IncomesExpenses income)
{
    CMarkup xml;
    Date date;

    if (fileExists(incomesFileName.c_str()) == false)
    {
        xml.AddElem( "INCOMES" );
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "USERID", income.getUserID());
        xml.AddElem( "INCOMEID", income.getIncomeOrExpenseID());
        xml.AddElem( "DATE", date.convertToDateWithDash(income.getDate()));
        xml.AddElem( "TITLE", income.getTitle());
        xml.AddElem( "AMOUNT", AuxiliaryMethods::convertFloatToString(income.getAmount()));
        xml.OutOfElem();
        xml.Save( incomesFileName.c_str() );
    }
    else
    {
        xml.Load(incomesFileName.c_str());
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "USERID", income.getUserID());
        xml.AddElem( "INCOMEID", income.getIncomeOrExpenseID());
        xml.AddElem( "DATE", date.convertToDateWithDash(income.getDate()));
        xml.AddElem( "TITLE", income.getTitle());
        xml.AddElem( "AMOUNT", AuxiliaryMethods::convertFloatToString(income.getAmount()));
        xml.OutOfElem();
        xml.Save( incomesFileName.c_str() );
    }
    lastIncomeID++;
}
vector <IncomesExpenses> IncomesFile::downloadLoggedInUserIncomes(int loggedInUserID)
{
    CMarkup xml;
    Date date;
    int dateInt;
    IncomesExpenses income;
    vector <IncomesExpenses> incomes;
    int userid;

    xml.Load(incomesFileName.c_str());
    xml.FindElem("INCOMES");
    xml.IntoElem();
    while (xml.FindElem("INCOME"))
    {
        xml.IntoElem();
        xml.FindElem("USERID");
        userid = atoi( MCD_2PCSZ(xml.GetData()));
        if (userid == loggedInUserID)
        {
            income.setUserID(userid);
            xml.FindElem( "INCOMEID" );
            income.setIncomeOrExpenseID(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "DATE" );
            income.setDate(date.convertDateToDateWithoutDash( MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "TITLE" );
            income.setTitle(MCD_2PCSZ(xml.GetData())) ;
            xml.FindElem( "AMOUNT" );
            income.setAmount(atof(MCD_2PCSZ(xml.GetData())));

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    if (fileExists(incomesFileName.c_str())== false || incomes.size() == 0)
    {
         lastIncomeID = 0;
    }
    else if (fileExists(incomesFileName.c_str())== true)
    {
        lastIncomeID = incomes.back().getIncomeOrExpenseID();
    }

    return incomes;
}
bool IncomesFile::fileExists (const string &fileName)
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
int IncomesFile::downloadLastIncomeID()
{
    return lastIncomeID;
}

