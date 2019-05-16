/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.cpp
 * Author: jt2603099
 *
 * Created on May 15, 2019, 10:20 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "MilTime.h"

using namespace std;

//Accessor / Getter functions
int MilTime::getHours() const {
    return milHours;
}
string MilTime::getStandHr() const {
    string full = "";
    full = to_string(getHour()) + ":" + to_string(getMin()) + ":" + to_string(getSec());
    return full;
}

