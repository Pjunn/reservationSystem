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
	cout << "\n���� �¼� ��Ȳ\n";
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
	cout << "\n�� �¼��� ���� Ƚ���� " << seat[seatNum - 1].showCount() << "ȸ �Դϴ�.\n";
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

