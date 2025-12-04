#include "BankDriver.h"

BankDriver::~BankDriver() {
	/*for (int i = 0; i < usersSize; i++) {
		delete *(users[usersSize]);
	}
	delete[] users;*/
}

BankDriver::BankDriver() {
	load();
}

void BankDriver::save() {
	cout << "Data saved!" << endl;
	return; // Needs to be implemented once User & Manager classes are complete
}

void BankDriver::load() {
	cout << "Data loaded!" << endl;
	return; // Needs to be implemented once User & Manager classes are complete
}

void BankDriver::mainScreen() {
	cout << "1. User Login\n2. Create Account\n3. Manager Login\n4. Exit" << endl;
	int nextScreen = 0;
	while (nextScreen > 4 || nextScreen < 1) {
		cin >> nextScreen;
		if (nextScreen > 4 || nextScreen < 1) {
			cout << "Incompatible Selection, value must be in range 1 - 4. Try Again." << endl;
		}
	}
	switch(nextScreen){
	case 1:
		userLoginScreen();
		break;
	case 2:
		createAccountScreen();
		break;
	case 3:
		managerLoginScreen();
		break;
	case 4:
		exit();
		break;
	}
	return;
}

void BankDriver::exit() {
	cout << "Exit" << endl;
	save();
}

void BankDriver::userLoginScreen() {
	cout << "User Login Screen" << endl;
	return; // Needs to be implemented once User & Manager classes are complete
}

void BankDriver::createAccountScreen() {
	cout << "Create Account Screen" << endl;
	return; // Needs to be implemented once User & Manager classes are complete
}

void BankDriver::managerLoginScreen() {
	cout << "Manager Login Screen" << endl;
	return; // Needs to be implemented once User & Manager classes are complete
}