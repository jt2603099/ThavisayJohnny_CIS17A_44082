/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.cpp
 * Author: jt2603099
 *
 * Created on May 12, 2019, 12:01 AM
 */

#include <iostream>
#include <cstdlib>

#include "NumDays.h"

using namespace std;

NumDays::NumDays() {
    hours = 0;
    days = 0;
}

NumDays::NumDays(double h = 0) {
    hours = h;
    days = h/(8.00);
}

double NumDays::getHours() {
    return hours;
}

double NumDays::getDays() {
    return days;
}

void NumDays::setHours(double h) {
    hours = h;
    days = h/(8.00);
}

void NumDays::setDays(double d) {
    days = d;
    hours = d*(8.00);
}

double NumDays::operator +(const NumDays& right) {
    return hours + right.hours;
}

double NumDays::operator -(const NumDays& right) {
    if (hours < right.hours) {
        cout << "Can't subtract!" <<endl;
        exit(0);
    }
    return hours - right.hours;
}

NumDays NumDays::operator ++() {
    ++hours;
    days = hours/(8.00);
    return *this;
}

NumDays NumDays::operator ++(int) {
    hours++;
    days = hours/(8.00);
    return *this;
}

NumDays NumDays::operator --() {
    --hours;
    days = hours/(8.00);
    return *this;
}

NumDays NumDays::operator --(int) {
    hours--;
    days = hours/(8.00);
    return *this;
}