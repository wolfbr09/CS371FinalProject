#include "User.h"

User::User(Login* loginPtr) : Person(loginPtr){
    accounts = nullptr;
    numAccounts = 0;
    capacity = 0;
}

User::~User() {
    for (int i = 0; i < numAccounts; i++) {
        delete accounts[i];
    }
    delete[] accounts;
}

void User::growAccountsArray() {
    int newCapacity;

    if (capacity == 0) {
        newCapacity = 1;
    }
    else {
        newCapacity = capacity * 2;
    }
    BankAccount** newArray = new BankAccount * [newCapacity];

    for (int i = 0; i < numAccounts; i++) {
        newArray[i] = accounts[i];
    }
    delete[] accounts;

    accounts = newArray;
    capacity = newCapacity;
}

bool User::addAccount(BankAccount* acct) {
    if (acct == nullptr) {
        return false;
    }

    if (numAccounts == capacity) {
        growAccountsArray();
    }

    accounts[numAccounts] = acct;
    numAccounts++;
    return true;
}

int User::getNumAccounts() {
    return numAccounts;
}

BankAccount* User::getAccountAt(int index) {
    if (index < 0 || index >= numAccounts) {
        return nullptr;
    }
    return accounts[index];
}

bool User::depositToAccount(int index, double amount) {
    BankAccount* acct = getAccountAt(index);
    if (acct == nullptr) {
        cout << "ERROR: Invalid account index." << endl;
        return false;
    }
    return acct->deposit(amount);
}

double User::withdrawFromAccount(int index, double amount) {
    BankAccount* acct = getAccountAt(index);
    if (acct == nullptr) {
        cout << "ERROR: Invalid account index." << endl;
        return 0.0;
    }
    return acct->withdraw(amount);
}

void User::printAccountSummary(int index) {
    BankAccount* acct = getAccountAt(index);
    if (acct == nullptr) {
        cout << "ERROR: Invalid account index." << endl;
        return;
    }
    acct->printAccountSummary();
}

void User::printAllAccounts() {
    cout << "Accounts for user: " << getUsername() << endl;
    for (int i = 0; i < numAccounts; i++) {
        cout << "  Account " << i << ":" << endl;
        accounts[i]->printAccountSummary();
    }
}
