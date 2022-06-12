#pragma once
#ifndef READINGROOMDATABASE_H
#define READINGROOMDATABASE_H

#include "Database.h"
#include <iostream>
#include <vector>
using namespace std;

class ReadingRoomDatabase : public Database {
	int seatData;
	vector<int> seatdataSet;
	vector<int> sexdataSet;
public:
	ReadingRoomDatabase();
	void addSeatdata(int clientNum);
	void cancelSeatdata(int clientNum);
	int getSeatdata(int clientNum);
	void addSexdata(int sex);
	void cancelSexdata(int sex);
	int getSexdata(int sex);

	void save();
};
#endif // !READINGROOMDATABASE_H
