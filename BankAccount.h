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

	int userNumber = -1; // Will need to be fixed once User class is created
	int accountNumber;
	string accountType;
	double balance;

	Transaction* transactionsHead;
	// And customer information?
	
public:
	BankAccount();
	BankAccount(double value);
	BankAccount(double value, string type);
	BankAccount(string type);
	BankAccount(int acctNum, double value, string type);
	BankAccount(BankAccount& acct);
	~BankAccount();
	
	double withdraw(double amount);
	bool deposit(double amount);
	void addNewTransaction(Transaction* tr);
	void printAccountSummary();

	double getBalance();
	string getAccountType();
	Transaction* getTransactions();

	static void save(BankAccount& acct);
	static void load();
};


#endif