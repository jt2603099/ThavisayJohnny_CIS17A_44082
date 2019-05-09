/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Payroll.cpp
 * Author: jt2603099
 *
 * Created on April 30, 2019, 7:55 PM
 */

#include <iostream>
#include <cstdlib>
#include "PayRoll.h"

using namespace std;

//Default constructor
PayRoll::PayRoll() {
        payRate = 0;
        weeklyPay = 0;
        hours = 0;
    }

//Overloaded constructor with parameters
PayRoll::PayRoll(int h, double rate) {
    hours = h;
    payRate = rate;
    weeklyPay = hours * hours;
}

//Setter functions / mutators
int PayRoll::setHours() {
    int h;
    cin >> h;
    while (h < 0 || h > 60) {
        cout << "No hours larger than 60!" <<endl;
        cin >> h;
    }
    hours = h;
    //Update weekly pay, so it's not stale
    weeklyPay = hours * payRate;
}

double PayRoll::setRate() {
    double r;
    cin >> r;
    while (r <= 0) {
        cout << "Pay rate can't be less than 0!" <<endl;
        cin >> r;
    }
    payRate = r;
    //Update weekly pay, so it's not stale
    weeklyPay = hours * payRate;
}
