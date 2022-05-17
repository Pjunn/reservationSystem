#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat() {
	name = { "---" };
}

void Seat::setName(string name) {
	this->name = name;
}

void Seat::resetName() {
	name = { "---" };
}

string Seat::showName() {
	return name;
}