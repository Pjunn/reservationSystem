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
	cout << "\n���� ���̺� ��Ȳ\n";
	cout << this->date << this->tableName << ":";
	for (int i = 0; i < 6; i++) {
		if (i == 0) {
			cout << "\t" << i + 1 << "�� ���̺�: " << table[i].showName() << "\n";
		}
		else {
			cout << "\t\t" << i + 1 << "�� ���̺�: " << table[i].showName() << "\n";
		}
	}
	cout << "\n";
}

bool Sale::setBook(int tableNum, string name) {
	if (table[tableNum - 1].showName() != "---") { // ������� �ʴٸ�
		cout << "\n�̹� ����� ���̺��Դϴ�. �ٸ� ���̺��� ����ּ���.\n";
		return false;
	}
	else {
		table[tableNum - 1].setName(name);
		cout << "\n����Ǿ����ϴ�.\n";
		return true;
	}

}

bool Sale::cancelBook(int tableNum, string name) {
	if (table[tableNum - 1].showName() == "---") {
		cout << "\n�̹� ����ִ� ���̺��Դϴ�.\n";
		return false;
	}
	else if (table[tableNum - 1].showName() != name) {
		cout << "\n����� �̸��� ��ġ���� �ʽ��ϴ�.\n";
		return false;
	}
	else {
		table[tableNum - 1].resetName();
		cout << "\n��ҵǾ����ϴ�.\n";
		return true;
	}
}

void Sale::showBookCount(int tableNum)
{
	cout << "\n�� �¼��� ���� Ƚ���� " << table[tableNum - 1].showCount() << "ȸ �Դϴ�.\n";
}

void Sale::addBookCount(int tableNum)
{
	table[tableNum - 1].countUp();
}

void Sale::cancelBookCount(int tableNum)
{
	table[tableNum - 1].countDown();
}
