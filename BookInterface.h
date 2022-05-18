#pragma once
#ifndef BOOKINTERFACE_H
#define BOOKINTERFACE_H

#include <iostream>
using namespace std;
#include "AirlineBook.h"
#include "RestaurantBook.h"

class BookInterface {
	int service;
	int loginmenu;
	AirlineBook airlineBook;
	RestaurantBook restaurantBook;
public:
	BookInterface();
	void start();
};

#endif // !BOOKINTERFACE_H
