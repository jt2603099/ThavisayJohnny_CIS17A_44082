/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.cpp
 * Author: jt2603099
 *
 * Created on May 15, 2019, 9:50 PM
 */

#include <iostream>
#include <cstdlib>

#include "Time.h"

using namespace std;

//default constructor
Time::Time() {
    hour = 0;
    min = 0;
    sec = 0;
}

//constructor
Time::Time(int h, int m, int s) {
    hour = h;
    min = m;
    sec = s;
}

//Accessor / getter functions
int Time::getHour() const {
    return hour;
}
int Time::getMin() const {
    return min;
}
int Time::getSec() const {
    return sec;
}

//Mutator / setter function
void Time::setHour(int h) {
    hour = h;
}
void Time::setMin(int m) {
    min = m;
}
void Time::setSec(int s) {
    sec = s;
}
