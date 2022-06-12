#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
using namespace std;

class Table {
	string name;
	int bookedCount;
public:
	Table();
	void setName(string name);
	void resetName();
	string showName();
	void countUp();
	void countDown();
	int showCount();
};

#endif // !TABLE_H
