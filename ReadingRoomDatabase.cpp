#include <iostream>
using namespace std;
#include "ReadingRoomDatabase.h"

ReadingRoomDatabase::ReadingRoomDatabase()
{
	this->seatData = 0;
	sexdataSet.push_back(0);
	sexdataSet.push_back(0);
}

void ReadingRoomDatabase::addSeatdata(int clientNum)
{
	seatdataSet[clientNum] += 1;
}

void ReadingRoomDatabase::cancelSeatdata(int clientNum)
{
	seatdataSet[clientNum] -= 1;
}

int ReadingRoomDatabase::getSeatdata(int clientNum)
{
	return seatdataSet[clientNum];
}

void ReadingRoomDatabase::addSexdata(int sex)
{
	sexdataSet[sex-1] += 1;
}

void ReadingRoomDatabase::cancelSexdata(int sex)
{
	sexdataSet[sex - 1] -= 1;
}

int ReadingRoomDatabase::getSexdata(int sex)
{
	return sexdataSet[sex - 1];
}

void ReadingRoomDatabase::save()
{
	seatdataSet.push_back(seatData);
}
