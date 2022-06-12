#pragma once
#ifndef RESTAURANTDATABASE_H
#define RESTAURANTDATABASE_H

#include "Database.h"
#include <iostream>
#include <vector>
using namespace std;

class RestaurantDatabase : public Database {
	int tableData;
	vector<int> tabledataSet;
public:
	RestaurantDatabase();
	void addTabledata(int clientNum);
	void cancelTabledata(int clientNum);
	int getTabledata(int clientNum);
	void save();
};
#endif // !RESTAURANTDATABASE_H
