#pragma once
#ifndef AIRLINEBOOK_H
#define AIRLINEBOOK_H

#include "BookingSystem.h"
#include <iostream>
#include "Account.h"
#include "Console.h"
#include "Schedule.h"
#include "AirlineDatabase.h"

using namespace std;

class AirlineBook : public BookingSystem {
	Account airlineAccount;
	Schedule**** schedule;
	AirlineDatabase airlineDatabase;
	int menu;
	int departureTime;
	int arrivalTime;
	int loginmenu;
	string id;
	string password;
	string name;
	int departureAirport;
	int arrivalAirport;
	int wayType;
	//string scheduleName;
	int date;
	int departureDate;
	int arrivalDate;
	int seatNum;
	int mileage;
	int budget;
	int economyTicketPrice;
	int businessTicketPrice;
	int information;
		
		
public:
	AirlineBook();
	~AirlineBook();
	void book();
	void login();
};
#endif // !AIRLINEBOOK_H
