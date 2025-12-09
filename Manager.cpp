#include "Manager.h"

Manager::Manager(string user, string pass) {
    username = user;
    password = pass;

}
Manager::Manager(Login* loginPtr) {
    login = loginPtr;
    users = nullptr;
    numUsers = 0;
    capacity = 0;
}

Manager::~Manager() {
    delete[] users;
}

void Manager::growUsersArray() {
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    User** newArray = new User * [newCapacity];

    for (int i = 0; i < numUsers; i++) {
        newArray[i] = users[i];
    }

    delete[] users;
    users = newArray;
    capacity = newCapacity;
}

string Manager::getUsername() {
    return (login != nullptr) ? login->getUsername() : "";
}

Login* Manager::getLogin() {
    return login;
}

bool Manager::addUser(User* user) {
    if (user == nullptr) {
        return false;
    }

    if (numUsers == capacity) {
        growUsersArray();
    }

    users[numUsers] = user;
    numUsers++;
    return true;
}

int Manager::getNumUsers() {
    return numUsers;
}

User* Manager::getUserAt(int index) {
    if (index < 0 || index >= numUsers) {
        return nullptr;
    }
    return users[index];
}

void Manager::viewAllUsers() {
    cout << "-------- All Users --------" << endl;
    for (int i = 0; i < numUsers; i++) {
        if (users[i] != nullptr) {
            cout << i << ": " << users[i]->getUsername() << endl;
        }
    }
    cout << "---------------------------" << endl;
}

void Manager::viewAllAccounts() {
    cout << "-------- All Accounts (by user) --------" << endl;
    for (int i = 0; i < numUsers; i++) {
        User* u = users[i];
        if (u == nullptr) continue;

        cout << "User: " << u->getUsername() << endl;
        for (int j = 0; j < u->getNumAccounts(); j++) {
            cout << "  Account " << j << ":" << endl;
            BankAccount* acct = u->getAccountAt(j);
            if (acct != nullptr) {
                acct->printAccountSummary();
            }
        }
    }
    cout << "----------------------------------------" << endl;
}

void Manager::viewSingleUserAccounts(User* user) {
    if (user == nullptr) {
        cout << "ERROR: Null user pointer." << endl;
        return;
    }
    user->printAllAccounts();
}

void Manager::viewSingleUserAccounts(int index) {
    User* u = getUserAt(index);
    if (u == nullptr) {
        cout << "ERROR: Invalid user index." << endl;
        return;
    }
    u->printAllAccounts();
}
