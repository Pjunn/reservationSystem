#include <iostream>
using namespace std;

#include "Sale.h"

Sale::Sale() {
	table = new Table[6];
}

Sale::~Sale() {
	delete[] table;
}

void Sale::setSaleName(int date, string tableName) {
	this->date = date;
	this->tableName = tableName;
}

void Sale::showSale() {
	cout << "\n현재 테이블 상황\n";
	cout << this->date << this->tableName << ":";
	for (int i = 0; i < 6; i++) {
		if (i == 0) {
			cout << "\t" << i + 1 << "번 테이블: " << table[i].showName() << "\n";
		}
		else {
			cout << "\t\t" << i + 1 << "번 테이블: " << table[i].showName() << "\n";
		}
	}
	cout << "\n";
}

bool Sale::setBook(int tableNum, string name) {
	if (table[tableNum - 1].showName() != "---") { // 비어있지 않다면
		cout << "\n이미 예약된 테이블입니다. 다른 테이블을 골라주세요.\n";
		return false;
	}
	else {
		table[tableNum - 1].setName(name);
		cout << "\n예약되었습니다.\n";
		return true;
	}

}

bool Sale::cancelBook(int tableNum, string name) {
	if (table[tableNum - 1].showName() == "---") {
		cout << "\n이미 비어있는 테이블입니다.\n";
		return false;
	}
	else if (table[tableNum - 1].showName() != name) {
		cout << "\n예약된 이름과 일치하지 않습니다.\n";
		return false;
	}
	else {
		table[tableNum - 1].resetName();
		cout << "\n취소되었습니다.\n";
		return true;
	}
}

void Sale::showBookCount(int tableNum)
{
	cout << "\n본 좌석의 예약 횟수는 " << table[tableNum - 1].showCount() << "회 입니다.\n";
}

void Sale::addBookCount(int tableNum)
{
	table[tableNum - 1].countUp();
}

void Sale::cancelBookCount(int tableNum)
{
	table[tableNum - 1].countDown();
}
