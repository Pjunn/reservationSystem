#pragma once

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include "Seat.h"
using namespace std;

class Schedule {
	Seat* seat;
	string scheduleName;
	int seatNum;
	string personName;
	int date;
public:
	Schedule();
	~Schedule();
	void setscheduleName(int date, string scheduleName);
	void showSchedule();
	bool setBook(int seatNum, string name);
	bool cancelBook(int seatNum, string name);
	void showScheduleEconomy();
	void showScheduleNone();
};
#endif // !SCHEDULE_H
