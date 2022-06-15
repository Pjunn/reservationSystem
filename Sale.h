#pragma once
#ifndef SALE_H
#define SALE_H

#include <iostream>
#include "Table.h"

using namespace std;

class Sale {
	Table* table;
	string tableName;
	int tableNum;
	string personNane;
	int date;
public:
	Sale();
	~Sale();
	void setSaleName(int date, string tableName);
	void showSale();
	bool setBook(int tableNum, string name);
	bool cancelBook(int tableNum, string name);
	void showBookCount(int tableNum);
	void addBookCount(int tableNum);
	void cancelBookCount(int tableNum);
	int getBookCount(int tableNum);
	void setBookCount(int tableNum, int bookCount);
	void setBookReload(int tableNum, string name);
};

#endif // !SALE_H
