#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include "Transaction.h"
#include <vector>

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
	int numTransactions = 1;

	vector<Transaction*> transactions;
	
public:
	BankAccount();
	BankAccount(double value);
	BankAccount(double value, string type);
	BankAccount(string type);
	BankAccount(int acctNum, double value, string type);
	BankAccount(BankAccount& acct);
	BankAccount(double value, string type, bool booleanThing);
	~BankAccount();
	
	double withdraw(double amount);
	bool deposit(double amount);
	void addNewTransaction(Transaction* tr);
	void printAccountSummary();

	double getBalance();
	string getAccountType();
	int getAccountNumber();
	vector<Transaction*> getTransactions();

	int getNumTransactions();

	static void save(BankAccount& acct);
	static void load();
};


#endif