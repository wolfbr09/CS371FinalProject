#include "Login.h"
// Contains the definitions for the Login class


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*				USE THIS WHEN HAVING USERS CREATE LOGIN
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Login* Login::createLogin() {
	string usr = enterUniqueUsername();
	string pass = enterSecurePassword();


	Login* newUser = new Login(usr, pass);
	users.push_back(newUser);
	usernames.push_back(usr);
	cout << "Login Creation Successful!" << endl;
	return newUser;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*							Constructors / Destructors
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Login::Login(string user, string pass) {
	username = user;
	password = pass;
}

Login::~Login() {
	usernames.erase(find(usernames.begin(), usernames.end(), username));
	users.erase(find(users.begin(), users.end(), this));
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*						Helper Functions
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Forces the user to make enter usernames until they enter a username not used.
string Login::enterUniqueUsername() {
	string usr;
	bool usrNotUnique = true;
	do {
		cout << "Enter username: ";
		cin >> usr;
		cout << endl;
		usrNotUnique = find(usernames.begin(), usernames.end(), usr) != usernames.end();
		if (usrNotUnique) {
			cout << "Username Invalid." << endl;
		}
	} while (usrNotUnique); // Make user enter usernames until they hit an unused username
	return usr;
}
// Forces the user to enter a password with is secure (see below requirements) and forces user to match that password. Returns the password when these conditions are met.
string Login::enterSecurePassword() {
	string pass;
	string passCheck;
	do {
		bool passSecure = false;
		cout << "Password must be greater than 10 characters and contain at least 1 number, at least 1 symbol, at least 1 uppercase letter, and at least 1 lowercase letter." << endl;
		do {
			cout << "Enter password: ";
			cin >> pass;
			cout << endl;
			passSecure = pass.length() >= 10 && any_of(pass.begin(), pass.end(), isdigit) && any_of(pass.begin(), pass.end(), isupper) && any_of(pass.begin(), pass.end(), ispunct) && any_of(pass.begin(), pass.end(), islower);
			if (!passSecure) {
				cout << "Password does not meet requirements." << endl;
			}
		} while (!passSecure); // Make the user enter passwords until the above requirements are met
		cout << "Password meets requirements!" << endl;

		cout << "Re-enter Password: ";
		cin >> passCheck;
		cout << endl;
		if (!pass.compare(passCheck)) {
			cout << "Passwords do not match." << endl;
		}
	} while (!pass.compare(passCheck)); // Make user enter passwords until the two passwords match
	
	return pass;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*						Member Functions
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
string Login::getUsername() {
	return username;
}
string Login::getPassword() {
	return password;
}
void Login::setPassword() {
	password = enterSecurePassword();
	cout << "Password Change Successful!" << endl;
}