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
	static string enterUniqueUsername();
	static string enterSecurePassword();
public:
	~Login();
	static Login* createLogin();
	Login(string user, string pass);
	string getUsername();
	string getPassword();
	void setPassword();
};


#endif