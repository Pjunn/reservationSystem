#include <iostream>
#include "RestaurantDatabase.h"
using namespace std;

RestaurantDatabase::RestaurantDatabase()
{
	this->tableData = 0;
}

void RestaurantDatabase::addTabledata(int clientNum)
{
	tabledataSet[clientNum] += 1;
}

void RestaurantDatabase::cancelTabledata(int clientNum)
{
	tabledataSet[clientNum] -= 1;
}

int RestaurantDatabase::getTabledata(int clientNum)
{
	return tabledataSet[clientNum];
}

void RestaurantDatabase::save()
{
	tabledataSet.push_back(tableData);
}
