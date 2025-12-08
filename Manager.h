#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include "Login.h"
#include "User.h"
#include "Person.h"

using namespace std;

class Manager : public Person {
private:
    string username;
	string password;
    Login* login;
    User** users;
    int numUsers;
    int capacity;

    void growUsersArray();

public:
    Manager(string user, string pass);
    Manager(Login* loginPtr);
    ~Manager();

    string getUsername() override;
    Login* getLogin();

    bool addUser(User* user);
    int getNumUsers();
    User* getUserAt(int index);

    void viewAllUsers();
    void viewAllAccounts();
    void viewSingleUserAccounts(User* user);
    void viewSingleUserAccounts(int index);
};

#endif
