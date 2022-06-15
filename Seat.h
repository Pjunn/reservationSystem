#pragma once
#ifndef SEAT_H
#define SEAT_H

#include <iostream>
using namespace std;

class Seat {
    string name;
    int bookedCount;
public:
    Seat();
    void setName(string name);
    void resetName();
    string showName();
    void countUp();
    void countDown();
    int showCount();
    void setCount(int count);
};
#endif // !SEAT_H
