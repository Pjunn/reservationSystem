#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
using namespace std;

class Account {
	string name;
	string id;
	string password;
	int clientNumber;
	int mileage;
	vector<string> nameSet;
	vector<string> idSet;
	vector<string> passwordSet;
public:
	Account();
	Account(string id, string password);
	void makeAccount();
	void setId(string id);
	void setPassword(string password);
	bool isregistered();
	string getName();
};
#endif // !ACCOUNT_H
