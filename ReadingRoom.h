#pragma once
#ifndef READINGROOM_H
#define READINGROOM_H

#include <iostream>
#include "Seat.h"
#include <string>
using namespace std;

class ReadingRoom {
	Seat** seat;
	string readingRoomName;
	int seatRow;
	int seatColumm;
	int date;
public:
	ReadingRoom();
	~ReadingRoom();
	void setreadingRoomName(int date, string readingRoomName);
	void showReadingRoom();
	bool setBook(int seatRow, int seatColumm, string name);
	bool cancelBook(int seatRow, int seatColumm,  string name);
	void showBookCount(int seatRow, int seatColumm);
	void addBookCount(int seatRow, int seatColumm);
	void cancelBookCount(int seatRow, int seatColumm);
	int getBookCount(int seatRow, int seatColumm);
	void setBookReload(int seatRow, int seatColumm, string name);
	void setBookCount(int seatRow, int seatColumm, int bookCount);
};
#endif // !READINGROOM_H
