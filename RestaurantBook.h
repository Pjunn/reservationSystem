#pragma once
#ifndef RESTAURANTBOOK_H
#define	RESTAURANTBOOK_H

#include "BookingSystem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Account.h"
#include "Console.h"
#include "Sale.h"
#include <queue>
#include "RestaurantDatabase.h"

using namespace std;

class RestaurantBook : public BookingSystem {
	Account restaurantAccount;
	Sale** sale;
	Table* walkinTable;
	queue<string> waitingQueue;
	vector<string> stringSet;
	RestaurantDatabase restaurantDatabase;
	ofstream fout;
	ifstream fin;
	string id;
	string password;
	string name;
	string bookInformation;
	string tableData;
	int loginmenu;
	int menu;
	int date;
	int isWalkIn;
	int memberNum;
	int isOver7;
	int whenEat;
	int tableNum;
	int finishMeal;
	int information;
public:
	RestaurantBook();
	~RestaurantBook();
	void book();
	void login();
};
#endif // !RESTAURANTBOOK_H
