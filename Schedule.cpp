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
	cout << this->date << this->scheduleName << ":";
	for (int i = 0; i < 8; i++) {
		cout << "\t" << seat[i].showName();
	}
	cout << "\n";
}

bool Schedule::setBook(int seatNum, string name) {
	if (seat[seatNum - 1].showName() != "---") { // ������� �ʴٸ�
		cout << "\n�̹� ����� �ڸ��Դϴ�. �ٸ� �ڸ��� ����ּ���.\n";
		return false;
	}
	else {
		seat[seatNum - 1].setName(name);
		cout << "\n����Ǿ����ϴ�.\n";
		return true;
	}
	
}

bool Schedule::cancelBook(int seatNum, string name) {
	if (seat[seatNum - 1].showName() == "---") {
		cout << "\n�̹� ����ִ� �ڸ��Դϴ�.\n";
		return false;
	}
	else if (seat[seatNum - 1].showName() != name) {
		cout << "\n����� �̸��� ��ġ���� �ʽ��ϴ�.\n";
		return false;
	}
	else {
		seat[seatNum - 1].resetName();
		cout << "\n��ҵǾ����ϴ�.\n";
		return true;
	}
}