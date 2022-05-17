#pragma once
#ifndef SEAT_H
#define SEAT_H

#include <iostream>
using namespace std;

class Seat {
    string name;
public:
    Seat();
    void setName(string name);
    void resetName();
    string showName();
};
#endif // !SEAT_H
