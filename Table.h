#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
using namespace std;

class Table {
	string name;
public:
	Table();
	void setName(string name);
	void resetName();
	string showName();
};

#endif // !TABLE_H
