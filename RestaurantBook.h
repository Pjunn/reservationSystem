#pragma once
#ifndef RESTAURANTBOOK_H
#define	RESTAURANTBOOK_H

#include "BookingSystem.h"
#include <iostream>
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
	RestaurantDatabase restaurantDatabase;
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
