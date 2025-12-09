#pragma once

#ifndef BANK_DRIVER_H
#define BANK_DRIVER_H

#include <iostream>
#include "User.h"
#include "Manager.h"
#include <vector>
#include "BankAccount.h"

using namespace std;

class BankDriver {
private:
	vector<User*> users;
	vector<Manager*> managers;
	int usersSize = 0;
	User* current_user = nullptr;
	Manager* current_manager = nullptr;
	string currentUsername = "";
	string currentPassword = "";
	void save();
	void load();

	static int getNextScreen(int lower, int higher);
	static string getStringDesc(string descriptor);
	void userScreen(User* user);
	void accountsScreen(User* user);
	void exit();
	void userLoginScreen();
	void createAccountScreen();
	void managerLoginScreen();
	void userScreen();
	void managerScreen();
	void accountsScreen();
	void bankAccountScreen(BankAccount* acct);
	void bankAccountViewScreen(BankAccount* acct, User* user);
	void viewUsersScreen();
public:
	BankDriver();
	~BankDriver();

	void mainScreen();
};


#endif