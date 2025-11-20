#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include "Transaction.h"

// Contains the Declaration of the BankAccount class

using namespace std;

class BankAccount {
private:
	static int activeAccounts;
	static int accountNumberCounter;

	int accountNumber;
	string accountType;
	double balance;

	Transaction* transactionsHead;
	// And customer information?

	BankAccount();
	BankAccount(double value);
	BankAccount(double value, string type);
	BankAccount(string type);
	BankAccount(BankAccount& acct);
	
	double withdraw(double amount);
	bool deposit(double amount);
	void addNewTransaction(Transaction* tr);
	void printAccountSummary();

	double getBalance();
	string getAccountType();
	Transaction* getTransactions();
};


#endif