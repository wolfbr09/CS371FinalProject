#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Login.h"
#include "BankAccount.h"
#include "Person.h"
using namespace std;

class User : public Person {
private:
    BankAccount** accounts;
    int numAccounts;
    int capacity;

    //Resize array if needed
    void growAccountsArray();

public:
    User(Login* loginPtr);
    ~User();

    string getUsername() override { return login->getUsername(); }
    bool addAccount(BankAccount* acct);
    int getNumAccounts();
    BankAccount* getAccountAt(int index);
    bool depositToAccount(int index, double amount);
    double withdrawFromAccount(int index, double amount);
    void printAccountSummary(int index);
    void printAllAccounts();
};

#endif
