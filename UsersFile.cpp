#include "UsersFile.h"

void UsersFile::addNewUserToFile(User user)
{
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
    xml.Load(usersFileName.c_str());
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
void UsersFile::saveAllUsersToFile(vector <User> users)
{
    CMarkup xml;
    for (vector <User> :: iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (fileExist("users.xml") == false)
        {
            xml.AddElem("Users");
            xml.IntoElem();
            xml.AddElem("User");
            xml.IntoElem();
            xml.AddElem( "UserID", itr->getUserID() );
            xml.AddElem( "login", itr->getLogin() );
            xml.AddElem( "password", itr->getPassword());
            xml.AddElem( "name", itr->getName());
            xml.AddElem( "surname", itr->getSurname());
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
            xml.AddElem( "UserID", itr->getUserID() );
            xml.AddElem( "login", itr->getLogin() );
            xml.AddElem( "password", itr->getPassword());
            xml.AddElem( "name", itr->getName());
            xml.AddElem( "surname", itr->getSurname());
            xml.OutOfElem();
            xml.Save( usersFileName.c_str() );
        }
    }
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
bool UsersFile::fileExist(string fileName)
{
    CMarkup xml;
    if (xml.Load(usersFileName.c_str()) == true)
        return true;
    else
        return false;
}
