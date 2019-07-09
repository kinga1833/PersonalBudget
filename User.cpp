#include "User.h"

void User::setUserID (int newID)
{
    if (newID >=0)
        userID = newID;
}
void User::setLogin (string newLogin)
{
    login = newLogin;
}
void User::setPassword (string newPassword)
{
    password = newPassword;
}
void User::setName (string newName)
{
    name = newName;
}
void User::setSurname (string newSurname)
{
    surname = newSurname;
}
int User::getUserID()
{
    return userID;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
string User::getName()
{
    return name;
}
string User::getSurname()
{
    return surname;
}
