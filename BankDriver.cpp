#include "BankDriver.h"

BankDriver::~BankDriver() {
	users.clear();
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
	int nextScreen = getNextScreen(1, 4);
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
	cout << "1. Enter Username\n2. Enter Password\n3. Login\n4. Back" << endl;
	cout << "Current Username: " << currentUsername << "\nCurrent Password: " << currentPassword << endl;
	int nextScreen = getNextScreen(1, 4);
	int i = 0;
	switch (nextScreen) {
	case 1:
		currentUsername = getStringDesc("username");
		userLoginScreen();
		break;
	case 2:
		currentPassword = getStringDesc("password");
		userLoginScreen();
		break;
	case 3:
		while (i < usersSize) {
			if (users.at(i)->getLogin()->getUsername().compare(currentUsername) != 0) {
				i++;
				continue;
			}
			if (users.at(i)->getLogin()->getPassword().compare(currentPassword) != 0) {
				i++;
				continue;
			}
			current_user = users.at(i);
			currentUsername = "";
			currentPassword = "";
			userScreen();
			break;
		}
		if (i == usersSize) {
			cout << "User not found" << endl;
			userLoginScreen();
		}
		break;
	case 4:
		currentUsername = "";
		currentPassword = "";
		mainScreen();
	}
	return;
}

void BankDriver::createAccountScreen() {
	cout << "Create Account Screen" << endl;
	users.push_back(new User(Login::createLogin()));
	usersSize++;
	mainScreen();
	return;
}

void BankDriver::managerLoginScreen() {
	cout << "Manager Login Screen" << endl;
	cout << "1. Enter Username\n2. Enter Password\n3. Login\n4. Back" << endl;
	cout << "Current Username: " << currentUsername << "\nCurrent Password: " << currentPassword << endl;
	int nextScreen = getNextScreen(1, 4);
	int i = 0;
	switch (nextScreen) {
	case 1:
		currentUsername = getStringDesc("username");
		managerLoginScreen();
		break;
	case 2:
		currentPassword = getStringDesc("password");
		managerLoginScreen();
		break;
	case 3:
		while (i < managers.size()) {
			if (managers.at(i)->getLogin()->getUsername().compare(currentUsername) != 0) {
				i++;
				continue;
			}
			if (managers.at(i)->getLogin()->getPassword().compare(currentPassword) != 0) {
				i++;
				continue;
			}
			current_manager = managers.at(i);
			currentUsername = "";
			currentPassword = "";
			managerScreen();
			break;
		}
		if (i == managers.size()) {
			cout << "Manager not found" << endl;
			managerLoginScreen();
		}
		break;
	case 4:
		currentUsername = "";
		currentPassword = "";
		mainScreen();
	}
	return;
}

void BankDriver::managerScreen() {
	cout << "Manager Screen" << endl;
	cout << "Manager Username: " << current_manager->getLogin()->getUsername() << endl;
	cout << "There is nothing to do here, this is just to prove that there is a manager class\n1. Logout" << endl;
	int nextScreen = getNextScreen(1, 1);
	switch (nextScreen) {
	case 1:
		current_manager = nullptr;
		cout << "Logged Out!" << endl;
		managerLoginScreen();
		break;
	}
	return;
}

void BankDriver::userScreen() {
	cout << "User Screen" << endl;
	cout << "Username: " << current_user->getLogin()->getUsername() << endl;
	cout << "1. View Accounts\n2. Create New Account\n3. Logout" << endl;
	int nextScreen = getNextScreen(1, 3);
	string accountDescription;
	switch (nextScreen) {
	case 1:
		accountsScreen();
		break;
	case 2:
		accountDescription = getStringDesc("account description");
		current_user->addAccount(new BankAccount(accountDescription));
		cout << "Account Added!" << endl;
		userScreen();
		break;
	case 3:
		current_user = nullptr;
		cout << "Logged Out!" << endl;
		userLoginScreen();
		break;
	}
	return;
}

void BankDriver::accountsScreen() {
	cout << "Accounts Screen" << endl;
	cout << "Username: " << current_user->getLogin()->getUsername() << endl;
	for (int i = 0; i < current_user->getNumAccounts(); i++) {
		cout << i << ". Account #" << current_user->getAccountAt(i)->getAccountNumber() << " " << current_user->getAccountAt(i)->getAccountType() << endl;
	}
	cout << current_user->getNumAccounts() << ". Go Back" << endl;
	int nextScreen = getNextScreen(0, current_user->getNumAccounts());
	if (nextScreen == current_user->getNumAccounts()) {
		userScreen();
		return;
	}
	bankAccountScreen(current_user->getAccountAt(nextScreen));
	return;
}

void BankDriver::bankAccountScreen(BankAccount* acct) {
	cout << "Bank Account Screen" << endl;
	cout << "Bank Account #" << acct->getAccountNumber() << endl;
	cout << "1. Withdrawal\n2. Deposit\n3. View Account Summary\n4. Back" << endl;
	int nextScreen = getNextScreen(1, 4);
	double amount = 0;
	switch (nextScreen) {
	case 1:
		cout << "Enter amount to withdraw: ";
		cin >> amount;
		acct->withdraw(amount);
		bankAccountScreen(acct);
		break;
	case 2:
		cout << "Enter amount to deposit: ";
		cin >> amount;
		acct->deposit(amount);
		bankAccountScreen(acct);
		break;
	case 3:
		acct->printAccountSummary();
		bankAccountScreen(acct);
		break;
	case 4:
		accountsScreen();
		break;
	}
	return;
}

int BankDriver::getNextScreen(int lower, int higher) {
	int nextScreen = -1;
	while (nextScreen > higher || nextScreen < lower) {
		cin >> nextScreen;
		if (nextScreen > higher || nextScreen < lower) {
			cout << "Incompatible Selection, value must be in range " << lower << " - " << higher << ". Try Again." << endl;
		}
	}
	return nextScreen;
}

string BankDriver::getStringDesc(string descriptor) {
	cout << "Please enter your " << descriptor << ": ";
	string val;
	cin >> val;
	return val;
}