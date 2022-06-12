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
	int BookCount;
	vector<string> nameSet;
	vector<string> idSet;
	vector<string> passwordSet;
	vector<int> mileageSet;
	vector<vector<int>> bookCountSet;
public:
	Account();
	Account(string id, string password);
	void makeAccount();
	void setId(string id);
	void setPassword(string password);
	bool isregistered();
	string getName();
	void addMileage();
	void minusMileage();
	int getMileage();
	void useBookCount(int date);
	void cancelBookCount(int date);
	int getBookCount(int date);
	int getClientNum();
};
#endif // !ACCOUNT_H
