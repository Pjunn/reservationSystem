#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <fstream>

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
	void makeAccount();
	void setId(string id);
	void setPassword(string password);
	void setName(string name);
	void pushId(string id);
	void pushPassword(string password);
	void pushName(string name);
	bool isregistered();
	string getName();
	string getId();
	string getPassword();
	void addMileage();
	void minusMileage();
	int getMileage();
	void useBookCount(int date);
	void cancelBookCount(int date);
	int getBookCount(int date);
	int getClientNum();
	void setBookCount(int date, int bookCount, int clientNumber);
};
#endif // !ACCOUNT_H
