#include "Transaction.h"

// Contains the definitions of the Transaction class

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*							Constructors
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Transaction::Transaction(int bankNum, double new_val) { 
	bankAccountNumber = bankNum;
	value = new_val;
	description = "default_description";
}
Transaction::Transaction(int bankNum, double new_val, string new_desc) { 
	bankAccountNumber = bankNum;
	value = new_val;
	description = new_desc; 
}
Transaction::Transaction(Transaction* other) { 
	bankAccountNumber = other->get_bank_num();
	value = other->get_value();
	description = other->get_description(); 
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*						Getters and Setters
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
double Transaction::get_value() { 
	return value; 
}
string Transaction::get_description() { 
	return description; 
}
void Transaction::set_description(string desc) {
	description = desc;
}

int Transaction::get_bank_num() {
	return bankAccountNumber;
}

void Transaction::set_bank_num(int newNum) {
	bankAccountNumber = newNum;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*						Saving and Loading
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Transaction::save(Transaction& trnsction) {
	return;
}

void Transaction::load() {
	return;
}