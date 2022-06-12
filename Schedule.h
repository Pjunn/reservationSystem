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
	//string personName;
	int date;
public:
	Schedule();
	~Schedule();
	void setscheduleName(int date, string scheduleName);
	void showSchedule();
	bool setBook(int seatNum, string name);
	bool cancelBook(int seatNum, string name);
	void showScheduleBusiness();
	void showScheduleEconomy();
	void showScheduleNone();
	void showBookCount(int seatNum);
	void addBookCount(int seatNum);
	void cancelBookCount(int seatNum);
};
#endif // !SCHEDULE_H
