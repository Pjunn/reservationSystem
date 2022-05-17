#include <iostream>
#include <vector>
using namespace std;

#include "Account.h"
#include "Console.h"

Account::Account() {
	this->mileage = 0;
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
	this->mileage += 100;
}

void Account::minusMileage() {
	this->mileage -= 100;
}

int Account::getMileage() {
	return mileage;
}