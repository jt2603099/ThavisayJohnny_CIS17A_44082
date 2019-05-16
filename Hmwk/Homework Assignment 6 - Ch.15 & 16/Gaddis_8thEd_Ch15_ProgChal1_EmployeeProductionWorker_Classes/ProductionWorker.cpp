/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductionWorker.cpp
 * Author: jt2603099
 *
 * Created on May 15, 2019, 4:14 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "ProductionWorker.h"

using namespace std;

//getter function / accessor function
string ProductionWorker::getShift() const {
    if (shift == 1) {
        return "Day";
        return "Night";
    }
}
double ProductionWorker::getPayRate() const {
    return payRate;
}

//setter / mutator function
void ProductionWorker::setShift(int s) {
    if (s != 1 && s != 2) {
        cout << "Shift input can only be 1 or 2!" <<endl;
        exit(EXIT_FAILURE);
    } else {
        shift = s;
    }
}
void ProductionWorker::setPayRate(double p) {
    if (p < 0) {
        cout << "Pay rate can not be NEGATIVE!" <<endl;
        exit(EXIT_FAILURE);
    } else {
        payRate = p;
    }
}


