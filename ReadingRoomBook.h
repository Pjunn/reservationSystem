#pragma once
#ifndef READINGROOMBOOK_H
#define READINGROOMBOOK_H

#include "BookingSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Account.h"
#include "Console.h"
#include "ReadingRoom.h"
#include "ReadingRoomDatabase.h"
#include <string>
using namespace std;

class ReadingRoomBook : public BookingSystem {
	Account readingRoomAccount;
	ReadingRoom** readingRoom;
	ReadingRoomDatabase readingRoomDatabase;
	ofstream fout;
	ifstream fin;
	string id;
	vector<string> stringSet;
	string password;
	string bookInformation;
	int loginmenu;
	int menu;
	int date;
	int floor; // Ãþ
	int isOver13;
	int sex;
	int readingRoomTime;
	int seatRow;
	int seatColumm;
	string name;
	string readingRoomName;
	int information;
public:
	ReadingRoomBook();
	~ReadingRoomBook();
	void book();
	void login();
};
#endif // !READINGROOMBOOK_H
