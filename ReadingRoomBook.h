#pragma once
#ifndef READINGROOMBOOK_H
#define READINGROOMBOOK_H

#include "BookingSystem.h"
#include <iostream>
#include "Account.h"
#include "Console.h"
#include "ReadingRoom.h"
#include <string>
using namespace std;

class ReadingRoomBook : public BookingSystem {
	Account readingRoomAccount;
	ReadingRoom** readingRoom;
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
public:
	ReadingRoomBook();
	~ReadingRoomBook();
	void book();
	void login();
};
#endif // !READINGROOMBOOK_H
