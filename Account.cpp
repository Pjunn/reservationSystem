#include <iostream>
#include <vector>
using namespace std;

#include "Account.h"
#include "Console.h"

Account::Account() {
	this->mileage = 0;
	this->BookCount = 4;
	this->clientNumber = -1;
}


bool Account::isregistered() { // 로그인할때 가입되어있지 않다면 오류메세지
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
	//fout.open("idSet.txt", ios::out|ios::app);
	name = Console::registerName();
	while (1) {
		int flag = 0;
		id = Console::loginID();
		for (int i = 0; i < idSet.size(); i++) {
			if (id == idSet[i]) {
				cout << "중복된 아이디 입니다. 아이디를 다시 입력해 주세요.\n";
				flag = 1;
				break;
			}
			
		}
		if (!flag) break;
	}
	password = Console::loginPass();
	nameSet.push_back(name);
	idSet.push_back(id);
	//fout << id << endl;
	passwordSet.push_back(password);
	mileageSet.push_back(mileage);
	vector<int> dailyBookCount(7, 4);
	bookCountSet.push_back(dailyBookCount);
	clientNumber = (int)idSet.size() - 1; // 인덱스로 접근하기 위한 번호
	//fout.close();
}

void Account::setId(string id) {
	this->id = id;
}

void Account::setPassword(string password) {
	this->password = password;
}

void Account::setName(string name)
{
	this->name = name;
}

void Account::pushId(string id)
{
	idSet.push_back(id);
	mileageSet.push_back(mileage);
	vector<int> dailyBookCount(7, 4);
	bookCountSet.push_back(dailyBookCount);
}

void Account::pushPassword(string password)
{
	passwordSet.push_back(password);
}

void Account::pushName(string name)
{
	nameSet.push_back(name);
}

string Account::getName() { // isregistered, makeAccount(로그인하고) 쓰고 난뒤에 사용가능
	return nameSet[clientNumber];
}

string Account::getId()
{
	return idSet[clientNumber];
}

string Account::getPassword()
{
	return passwordSet[clientNumber];
}

int Account::getClientNum() {
	return clientNumber;
}

void Account::setBookCount(int date, int bookCount, int clientNumber)
{
	bookCountSet[clientNumber][date - 1] = bookCount;
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