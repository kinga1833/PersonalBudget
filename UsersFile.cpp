#include "UsersFile.h"

void UsersFile::addNewUserToFile(User user)
{
    fstream xmlFile;
    CMarkup xml;

    if (fileExist("users.xml") == false)
    {
        xml.AddElem("Users");
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem( "UserID", user.getUserID() );
        xml.AddElem( "login", user.getLogin() );
        xml.AddElem( "password", user.getPassword());
        xml.AddElem( "name", user.getName());
        xml.AddElem( "surname", user.getSurname());
        xml.OutOfElem();
        xml.Save( usersFileName.c_str() );
    }
    else
    {
        xml.Load(usersFileName.c_str());
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem( "UserID", user.getUserID() );
        xml.AddElem( "login", user.getLogin() );
        xml.AddElem( "password", user.getPassword());
        xml.AddElem( "name", user.getName());
        xml.AddElem( "surname", user.getSurname());
        xml.OutOfElem();
        xml.Save( usersFileName.c_str() );
    }
}
vector <User> UsersFile::loadUsersFromFile()
{
    CMarkup xml;
    User user;
    vector <User> users;
    string userId, userLogin, userPassword, userName, userSurname;
    xml.Load("users.xml");
    xml.FindElem("Users");
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserID");
        userId = xml.GetData();
        user.setUserID(AuxiliaryMethods::convertStringToInt(userId));
        xml.FindElem("login");
        userLogin = xml.GetData();
        user.setLogin(userLogin);
        xml.FindElem("password");
        userPassword = xml.GetData();
        user.setPassword(userPassword);
        xml.FindElem("name");
        userName = xml.GetData();
        user.setName(userName);
        xml.FindElem("surname");
        userSurname = xml.GetData();
        user.setSurname(userSurname);
        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}
bool UsersFile::checkIfFileIsEmpty()
{
    fstream xmlFile;
    xmlFile.seekg(0, ios::end);
    if (xmlFile.tellg() == 0)
        return true;
    else
        return false;
}
void UsersFile::saveAllUsersDoFile(vector <User> users)
{
    fstream xmlFile;
    vector <User>::iterator itrEnd = --users.end();

    xmlFile.open(usersFileName.c_str(), ios::out);

    if (xmlFile.good() == true)
    {
        for (int i=0; i<users.size(); i++)
        {
            xmlFile << "<userID>" << users[i].getUserID()<< "<userID>" << endl;
            xmlFile << "<login>" << users[i].getLogin() << "<login>" << endl;
            xmlFile << "<password>" << users[i].getPassword() << "<password>" << endl;
            xmlFile << "<name>" << users[i].getName() << "<name>" << endl;
            xmlFile << "<surname>" << users[i].getSurname() << "<surname>" << endl;
        }
        xmlFile.close();
    }
    else
    {
        cout << "File can't be opened." << endl;
    }
}
 bool UsersFile::fileExist(string fileName)
 {
     CMarkup xml;
     if (xml.Load(usersFileName.c_str()) == true)
        return true;
     else
        return false;
 }
