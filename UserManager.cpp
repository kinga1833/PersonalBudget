#include "UserManager.h"

void UserManager::userRegister()
{
    cout << " >>> REGISTER <<< " << endl << endl;
    User user = provideDataOfNewUser();
    users.push_back(user);
    usersFile.addNewUserToFile(user);

    cout << endl << "New account has been created!" << endl << endl;
    system("pause");

}
User UserManager::provideDataOfNewUser()
{
    User user;

    user.setUserID(downloadNewUserID());

    string login;
    do
    {
        cout <<"Login: ";
        cin >>login;
        user.setLogin(login);
    }
    while (checkIfLoginExist(user.getLogin()) == true);

    string password;
    do
    {
        cout << "Password: ";
        cin >> password;
        user.setPassword(password);
    }
    while (checkIfPasswordExist(user.getPassword())== true);

    string name;
    cout << "Name: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Surame: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}
int UserManager::downloadNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID() + 1;
}
bool UserManager::checkIfLoginExist(string login)
{
    for (int i = 0; i< users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "This login already exist." << endl;
            return true;
        }
    }
    return false;
}
bool UserManager::checkIfPasswordExist(string password)
{
    for (int i = 0; i< users.size(); i++)
    {
        if (users[i].getPassword() == password)
        {
            cout << endl << "This password already exist." << endl;
            return true;
        }
    }
    return false;
}
bool UserManager::checkIfUserIsLoggedIn()
{
    if(loggedInUserID > 0)
        return true;
    else
        return false;
}

void UserManager::showAllUsers()
{
    for (int i = 0; i< users.size(); i++)
    {
        cout << users[i].getUserID() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}
int UserManager::logIn()
{
    string login = "", password = "";
    cout << ">>>  LOG IN <<<" << endl << endl;
    cout << "Login: ";
    cin >> login;

    while (true)
    {
        for (int i=0; i<users.size(); i++)
        {
            if(users[i].getLogin() == login)
            {
                for (int numberOfTries = 3; numberOfTries > 0; numberOfTries--)
                {
                    cout << "Password: ";
                    cin >> password;

                    if (users[i].getPassword() == password)
                    {
                        loggedInUserID = users[i].getUserID();
                        cout << endl << "You are logged in."<< endl << endl;
                        system("pause");
                        return loggedInUserID;
                    }
                }
                cout << "You entered wrong password 3 times." << endl;
                system("pause");
                return 0;
            }
        }
        cout << "User with this login doesn't exist." << endl << endl;
        system("pause");
        return 0;
    }
}
void UserManager::changePassword()
{
    cout << endl << ">>>  CHANGE PASSWORD <<<" << endl << endl;
    string newPassword = "";
    cout << "New password: ";
    cin >> newPassword;

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getUserID() == loggedInUserID)
        {
            users[i].setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    usersFile.saveAllUsersToFile(users);
}
void UserManager::logOut()
{
    loggedInUserID = 0;
}
int UserManager::getLoggedInUserID()
{
    return loggedInUserID;
}
