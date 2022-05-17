#pragma once
#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <iostream>
using namespace std;


class BookingSystem {
public:
	BookingSystem();
	//void start();
	virtual void book() {};
	virtual void login() {};
};
#endif // !BOOKINGSYSTEM_H

