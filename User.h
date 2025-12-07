#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Login.h"
#include "BankAccount.h"
using namespace std;

class User {
private:
    Login* login;

    BankAccount** accounts;
    int numAccounts;
    int capacity;

    //Resize array if needed
    void growAccountsArray();

public:
    User(Login* loginPtr);
    ~User();

    string getUsername();
    Login* getLogin();
    bool addAccount(BankAccount* acct);
    int getNumAccounts();
    BankAccount* getAccountAt(int index);
    bool depositToAccount(int index, double amount);
    double withdrawFromAccount(int index, double amount);
    void printAccountSummary(int index);
    void printAllAccounts();
};

#endif
