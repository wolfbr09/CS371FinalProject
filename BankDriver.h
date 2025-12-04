#pragma once

#ifndef BANK_DRIVER_H
#define BANK_DRIVER_H

#include <iostream>
using namespace std;

class BankDriver {
private:
	//USER_CLASS_NAME_HERE* users[];
	//int usersSize = 0;
	//USER_CLASS_NAME_HERE* current_user;
	void save();
	void load();
public:
	BankDriver();
	~BankDriver();
	void mainScreen();
	void exit();
	void userLoginScreen();
	void createAccountScreen();
	void managerLoginScreen();
};


#endif