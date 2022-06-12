#include <iostream>
using namespace std;

#include "Schedule.h"

Schedule::Schedule() {
	seat = new Seat[8];
}

Schedule::~Schedule() {
	delete[] seat;
}

void Schedule::setscheduleName(int date, string scheduleName) {
	this->date = date;
	this->scheduleName = scheduleName;
}

void Schedule::showSchedule() {
	cout << "\n현재 좌석 상황\n";
	cout << this->date << this->scheduleName << ":";
	for (int i = 0; i < 8; i++) {
		cout << "\t" << seat[i].showName();
	}
	cout << "\n";
}

void Schedule::showScheduleBusiness() {
	cout << this->date << this->scheduleName << ":";
	for (int i = 0; i < 8; i++) {
		cout << "\t" << seat[i].showName();
	}
	cout << "\n";
}

void Schedule::showScheduleEconomy() {
	cout << this->date << this->scheduleName << ":";
	for (int i = 0; i < 8; i++) {
		if (i > 3) {
			cout << "\t" << seat[i].showName();
		}
		else {
			cout << "\t" << "xxx";
		}
	}
	cout << "\n\n";
}

void Schedule::showScheduleNone() {
	cout << this->date << this->scheduleName << ":";
	for (int i = 0; i < 8; i++) {
		cout << "\t" << "xxx";
	}
	cout << "\n\n";
}

void Schedule::showBookCount(int seatNum)
{
	cout << "\n본 좌석의 예약 횟수는 " << seat[seatNum - 1].showCount() << "회 입니다.\n";
}

void Schedule::addBookCount(int seatNum)
{
	seat[seatNum - 1].countUp();
}

void Schedule::cancelBookCount(int seatNum)
{
	seat[seatNum - 1].countDown();
}

bool Schedule::setBook(int seatNum, string name) {
	if (seat[seatNum - 1].showName() != "---") { // 비어있지 않다면
		cout << "\n이미 예약된 자리입니다. 다른 자리를 골라주세요.\n";
		return false;
	}
	else {
		seat[seatNum - 1].setName(name);
		cout << "\n예약되었습니다.\n";
		return true;
	}
	
}

bool Schedule::cancelBook(int seatNum, string name) {
	if (seat[seatNum - 1].showName() == "---") {
		cout << "\n이미 비어있는 자리입니다.\n";
		return false;
	}
	else if (seat[seatNum - 1].showName() != name) {
		cout << "\n예약된 이름과 일치하지 않습니다.\n";
		return false;
	}
	else {
		seat[seatNum - 1].resetName();
		cout << "\n취소되었습니다.\n";
		return true;
	}
}

