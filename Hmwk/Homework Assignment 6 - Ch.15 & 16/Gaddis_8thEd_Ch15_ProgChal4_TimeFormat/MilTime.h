/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.h
 * Author: jt2603099
 *
 * Created on May 15, 2019, 9:53 PM
 */

#ifndef MILTIME_H
#define MILTIME_H
#include <iostream>
#include <string>

#include "Time.h"

using namespace std;

class MilTime : public Time {
protected:
    int milHours, milSeconds;
public:
    //default constructor of base class
    MilTime() : Time() {
        milHours = 0;
        milSeconds = 0;
    }
    
    //Miltime takes two parameters and calls the overloaded constructor 
    //of it's base class Time of 3 parameters
    MilTime(int mH, int mS) : Time(mH / 100, mH % 100, mS) {
        if (mH < 0 || mH > 2359) {
            cout << mH << " is not a valid value for military time!" <<endl;
            exit(EXIT_FAILURE);
        } else if (mS < 0 || mS > 59) {
            cout << mS << " is not a valid value for military time!" <<endl;
            exit(EXIT_FAILURE);
        } else {
            milHours = mH;
            milSeconds = mS;
        }
    }
    
    void setTime(int mH, int mS) {
        if (mH < 0 || mH > 2359) {
            cout << mH << " is not a valid value for military time!" <<endl;
            exit(EXIT_FAILURE);
        } else if (mS < 0 || mS > 59) {
            cout << mS << " is not a valid value for military time!" <<endl;
            exit(EXIT_FAILURE);
        } else {
            milHours = mH;
            milSeconds = mS;
            while ((mH % 100) > 59) {
                cout << mH << " is an invalid time! Enter different time: ";
                cin >> mH;
            }
            Time::setHour(mH/100);
            Time::setMin(mH%100);
            Time::setSec(mS);
        }
    }
    
    //Accessor / Getter functions
    int getHours() const;
    string getStandHr() const;
};

#endif /* MILTIME_H */

