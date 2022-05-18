#pragma once

#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
using namespace std;

class Console {
public:
	static void greeting();
	static int select_service();
	static int select_menu();
	static int select_time();
	static int select_seat();
	static int select_airport();
	static int select_waytype();
	static int select_date();
	static int getBudget();
	static int isWalkIn();
	static int select_table();
	static int select_whenEat();


	static int loginMenu();
	static string registerName();
	static string loginID();
	static string loginPass();
	static int memberNum();
	static int isOver7();
	static int finishMeal();
};

#endif // !CONSOLE_H
