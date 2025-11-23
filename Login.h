#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Login {
private:
	static vector<Login*> users;
	static vector<string> usernames;
	string username;
	string password;
	Login(string user, string pass);
	~Login();
	static string enterUniqueUsername();
	static string enterSecurePassword();
public:
	static Login* createLogin();
	string getUsername();
	string getPassword();
	void setPassword();
};


#endif