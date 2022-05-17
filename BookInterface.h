#pragma once
#ifndef BOOKINTERFACE_H
#define BOOKINTERFACE_H

#include <iostream>
using namespace std;
#include "AirlineBook.h"

class BookInterface {
	int service;
	int loginmenu;
	AirlineBook airlineBook;
public:
	BookInterface();
	void start();
};

#endif // !BOOKINTERFACE_H
