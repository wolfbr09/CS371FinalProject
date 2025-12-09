#include "BankAccount.h"
// Contains the definitions for the BankAccount class


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*							Constructors
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
BankAccount::BankAccount() {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = 0;
	accountType = "";
	transactions.push_back(new Transaction(accountNumber, 0, "Balance as of Account Open"));
}

BankAccount::BankAccount(double value) {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = value;
	accountType = "";
	transactions.push_back(new Transaction(accountNumber, value, "Balance as of Account Open"));
}

BankAccount::BankAccount(double value, string type) {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = value;
	accountType = type;
	transactions.push_back(new Transaction(accountNumber, value, "Balance as of Account Open"));
}

BankAccount::BankAccount(string type) {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = 0;
	accountType = type;
	transactions.push_back(new Transaction(accountNumber, 0, "Balance as of Account Open"));
}

BankAccount::BankAccount(BankAccount& acct) {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = acct.getBalance();
	accountType = acct.getAccountType();
	transactions.push_back(new Transaction(accountNumber, acct.getBalance(), "Balance as of Account Open"));
}

// This should ONLY be used when loading data
BankAccount::BankAccount(int acctNum, double value, string type){
	accountNumber = acctNum;
	balance = value;
	accountType = type;
}

BankAccount::~BankAccount() {
	for (int i = 0; i < transactions.size(); i++) {
		delete transactions.at(i);
	}
	transactions.clear();
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*						Static Variables
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int BankAccount::accountNumberCounter = 10000000;
int BankAccount::activeAccounts = 0;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*						Member Functions
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Removes amount from account balance if amount is greater than 0 and is less than or equal to balance. Adds transaction to end of transactions linked list. Returns amount removed
double BankAccount::withdraw(double amount) {
	if (amount <= 0) {
		cout << "ERROR: Amount needs to be greater than 0" << endl;
		return 0;
	}
	if (amount > balance) {
		cout << "ERROR: Insufficient Funds" << endl;
		return 0;
	}

	addNewTransaction(new Transaction(accountNumber, -amount));
	balance -= amount;
	return amount;
}
// Adds amount to account balance if amount if greater than 0. Adds transaction to end of transactions linked list. Returns true if successful
bool BankAccount::deposit(double amount) {
	if (amount <= 0) {
		cout << "ERROR: Amount needs to be greater than 0" << endl;
		return false;
	}

	addNewTransaction(new Transaction(accountNumber, amount));
	balance += amount;
	return true;
}

// Prints Account Number, balance, and transaction history
void BankAccount::printAccountSummary() {
	cout << "---------------------------------------" << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Current Balance: $" << balance << endl;
	cout << "-----Transaction History (Oldest to Newest)-----" << endl;
	for (int i = 0; i < transactions.size(); i++) {
		cout << i << ": $" << transactions.at(i)->get_value() << " : " << transactions.at(i)->get_description() << endl;
	}
	cout << "---------------------------------------" << endl;
}

// Adds a new transaction to the end of the transactionsHead linked list
void BankAccount::addNewTransaction(Transaction* tr) {
	transactions.push_back(tr);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*						Getters and Setters
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
double BankAccount::getBalance() {
	return balance;
}
string BankAccount::getAccountType() {
	return accountType;
}

vector<Transaction*> BankAccount::getTransactions() { 
	return transactions;
}

int BankAccount::getAccountNumber() {
	return accountNumber;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*						Saving and Loading
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void BankAccount::save(BankAccount& acct) {
	return;
}

void BankAccount::load() {
	return;
}