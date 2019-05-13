/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.cpp
 * Author: jt2603099
 *
 * Created on May 12, 2019, 7:41 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "TimeOff.h"

using namespace std;

//default constructor
TimeOff::TimeOff() {
    int i = 0;
    name = "";
    numberID = ++i;
}
//constructor
TimeOff::TimeOff(string n, int id) {
    name = n;
    numberID = id;
}

//accessor / getter function
string TimeOff::getName() const {
    return name;
}

int TimeOff::getID() const {
    return numberID;
}

double TimeOff::getMaxSickDays() {
    return maxSickDays.getDays();
}

double TimeOff::getSickTaken() {
    return sickTaken.getDays();
}

double TimeOff::getMaxVacation() {
    return maxVacation.getDays();
}

double TimeOff::getVacTaken() {
    return vacTaken.getDays();
}

double TimeOff::getMaxUnpaid() {
    return maxUnpaid.getDays();
}

double TimeOff::getUnpaidTaken() {
    return unpaidTaken.getDays();
}

//setter functions / mutators
void TimeOff::setName(string n) {
    name = n;
}

void TimeOff::setID(int id) {
    numberID = id;
}

void TimeOff::setMaxSickDays(double h) {
    maxSickDays.setHours(h);
}

void TimeOff::setSickTaken(double h) {
    sickTaken.setHours(h);
}

void TimeOff::setMaxVacation(double h) {
    if (h > 240) {
        maxVacation.setHours(240);
    } else {
        maxVacation.setHours(h);
    }
}

void TimeOff::setVacTaken(double h) {
    vacTaken.setHours(h);
}

void TimeOff::setMaxUnpaid(double h) {
    maxUnpaid.setHours(h);
}

void TimeOff::setUnpaidTaken(double h) {
    unpaidTaken.setHours(h);
}