#include <iostream>
using namespace std;

#include "Table.h"

Table::Table() {
	name = { "---" };
	this->bookedCount = 0;
}

void Table::setName(string name) {
	this->name = name;
}

void Table::resetName() {
	name = { "---" };
}

string Table::showName() {
	return name;
}

void Table::countUp(){
	bookedCount += 1;
}

void Table::countDown(){
	bookedCount -= 1;
}

int Table::showCount(){
	return bookedCount;
}
