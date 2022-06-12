#pragma once
#ifndef AIRLINEDATABASE_H
#define AIRLINEDATABASE_H

#include "Database.h"
#include <iostream>
#include <vector>
using namespace std;

class AirlineDatabase : public Database {
	int seatData;
	vector<int> seatdataSet;
public:
	AirlineDatabase();
	void addSeatdata(int clientNum);
	void cancelSeatdata(int clientNum);
	int getSeatdata(int clientNum);
	void save();
};
#endif // !AIRLINEDATABASE_H
