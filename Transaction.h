#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

// Contains the declaration of the Transaction class

using namespace std;

class Transaction{
private:
	double value;
	string description;
	Transaction* next = 0;
	Transaction* previous = 0;
	int bankAccountNumber = -1;
public:
	// Constructors
	Transaction(int bankNum, double new_val);
	Transaction(int bankNum, double new_val, string new_desc);
	Transaction(Transaction* other);
	// Getters & Setters
	double get_value();
	string get_description();
	void set_description(string desc);
	void set_next(Transaction* new_next);
	void set_previous(Transaction* new_prev);
	Transaction* get_next();
	Transaction* get_previous();
	int get_bank_num();
	void set_bank_num(int newNum);
	
	static void save(Transaction& trnsction);
	static void load();
};

#endif