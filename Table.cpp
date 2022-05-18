#include <iostream>
using namespace std;

#include "Table.h"

Table::Table() {
	name = { "---" };
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