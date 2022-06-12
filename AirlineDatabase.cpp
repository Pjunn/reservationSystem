#include <iostream>
using namespace std;

#include "AirlineDatabase.h"

AirlineDatabase::AirlineDatabase() {
	this->seatData = 0;
}

void AirlineDatabase::addSeatdata(int clientNum){
	seatdataSet[clientNum] += 1;
}

void AirlineDatabase::cancelSeatdata(int clientNum) {
	seatdataSet[clientNum] -= 1;
}

int AirlineDatabase::getSeatdata(int clientNum)
{
	return seatdataSet[clientNum];
}

void AirlineDatabase::save() {
	seatdataSet.push_back(seatData);
}
