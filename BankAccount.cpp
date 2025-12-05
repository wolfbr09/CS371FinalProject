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
	transactionsHead = new Transaction(accountNumber, 0, "Balance as of Account Open");
}

BankAccount::BankAccount(double value) {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = value;
	accountType = "";
	transactionsHead = new Transaction(accountNumber, value, "Balance as of Account Open");
}

BankAccount::BankAccount(double value, string type) {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = value;
	accountType = type;
	transactionsHead = new Transaction(accountNumber, value, "Balance as of Account Open");
}

BankAccount::BankAccount(string type) {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = 0;
	accountType = type;
	transactionsHead = new Transaction(accountNumber, 0, "Balance as of Account Open");
}

BankAccount::BankAccount(BankAccount& acct) {
	accountNumber = accountNumberCounter;
	accountNumberCounter++;
	activeAccounts++;
	balance = acct.getBalance();
	accountType = acct.getAccountType();
	transactionsHead = new Transaction(accountNumber, acct.getBalance(), "Balance as of Account Open");
}

// This should ONLY be used when loading data
BankAccount::BankAccount(int acctNum, double value, string type){
	accountNumber = acctNum;
	balance = value;
	accountType = type;
	transactionsHead = 0;
}

BankAccount::~BankAccount() {
	Transaction* currTransaction = transactionsHead;
	while (currTransaction != nullptr) {
		Transaction* prevTransaction = currTransaction;
		currTransaction = currTransaction->get_next();
		delete prevTransaction;
	}
	transactionsHead = nullptr;
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
	int counter = 0;
	Transaction* curr = transactionsHead;
	while (curr != nullptr) {
		cout << counter << ": $" << curr->get_value() << " : " << curr->get_description() << endl;
		counter++;
	}
	cout << "---------------------------------------" << endl;
}

// Adds a new transaction to the end of the transactionsHead linked list
void BankAccount::addNewTransaction(Transaction* tr) {
	Transaction* curr = transactionsHead;
	while (curr->get_next() != nullptr) {
		curr = curr->get_next();
	}
	curr->set_next(tr);
	tr->set_previous(curr);
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

Transaction* BankAccount::getTransactions() { 
	return transactionsHead; 
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