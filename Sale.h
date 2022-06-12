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
	bool setBook(int tableNum, string tableName);
	bool cancelBook(int tableNum, string tableName);
	void showBookCount(int tableNum);
	void addBookCount(int tableNum);
	void cancelBookCount(int tableNum);
};

#endif // !SALE_H
