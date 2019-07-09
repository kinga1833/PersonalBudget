#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"
#include "UsersFile.h"
#include "Markup.h"

using namespace std;

class UserManager
{
    int loggedInUserID;
    vector <User> users;
    UsersFile usersFile;
    User provideDataOfNewUser();
    int downloadNewUserID();
    bool checkIfLoginExist(string login);
    bool checkIfPasswordExist(string password);


public:
    UserManager (string usersFileName)
        : usersFile(usersFileName)
    {
        users = usersFile.loadUsersFromFile();
        loggedInUserID = 0;
    };
    int getLoggedInUserID();
    bool checkIfUserIsLoggedIn();
    void userRegister();
    void showAllUsers();
    int logIn();
    void changePassword();
    void logOut();
};

#endif
