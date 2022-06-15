#include <iostream>
using namespace std;

#include "Seat.h"

Seat::Seat() {
	name = { "---" };
	this->bookedCount = 0;
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

void Seat::countUp(){
	bookedCount += 1;
}

void Seat::countDown(){
	bookedCount -= 1;
}

int Seat::showCount() {
	return bookedCount;
}

void Seat::setCount(int count)
{
	bookedCount = count;
}
