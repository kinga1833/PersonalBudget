#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class UsersFile
{
    string usersFileName;

    bool checkIfFileIsEmpty();
public:
    UsersFile(string USERSFILENAME): usersFileName (USERSFILENAME){};
    void addNewUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
    bool fileExist(string fileName);
};

#endif
