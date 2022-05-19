#include <iostream>
#include <vector>
using namespace std;

#include "Account.h"
#include "Console.h"

Account::Account() {
	this->mileage = 0;
	this->BookCount = 4;
}
Account::Account(string id, string password) {
	this->id = id;
	this->password = password;
}

bool Account::isregistered() { // �α����Ҷ� ���ԵǾ����� �ʴٸ� �����޼���
	for (int i = 0; i < idSet.size(); i++) {
		if (id == idSet[i]) {
			if (password == passwordSet[i]) {
				clientNumber = i;
				return true;
			}
			else return false;
		}
	}
	return false;
}

void Account::makeAccount() {
	name = Console::registerName();
	while (1) {
		int flag = 0;
		id = Console::loginID();
		for (int i = 0; i < idSet.size(); i++) {
			if (id == idSet[i]) {
				cout << "�ߺ��� ���̵� �Դϴ�. ���̵� �ٽ� �Է��� �ּ���.\n";
				flag = 1;
				break;
			}
		}
		if (!flag) break;
	}
	password = Console::loginPass();
	nameSet.push_back(name);
	idSet.push_back(id);
	passwordSet.push_back(password);
	mileageSet.push_back(mileage);
	vector<int> dailyBookCount(7, 4);
	bookCountSet.push_back(dailyBookCount);
	clientNumber = (int)idSet.size() - 1; // �ε����� �����ϱ� ���� ��ȣ
}

void Account::setId(string id) {
	this->id = id;
}

void Account::setPassword(string password) {
	this->password = password;
}

string Account::getName() { // isregistered, makeAccount(�α����ϰ�) ���� ���ڿ� ��밡��
	return nameSet[clientNumber];
}

void Account::addMileage() {
	mileageSet[clientNumber] += 100;
}

void Account::minusMileage() {
	mileageSet[clientNumber] -= 100;
}

int Account::getMileage() {
	return mileageSet[clientNumber];
}

void Account::useBookCount(int date) {
	bookCountSet[clientNumber][date - 1] -= 1;
}

void Account::cancelBookCount(int date) {
	bookCountSet[clientNumber][date - 1] += 1;
}

int Account::getBookCount(int date) {
	return bookCountSet[clientNumber][date - 1];
}