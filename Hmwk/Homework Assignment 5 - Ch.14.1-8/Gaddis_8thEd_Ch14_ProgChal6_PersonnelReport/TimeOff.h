/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: jt2603099
 *
 * Created on May 12, 2019, 7:40 PM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include <iostream>
#include <string>

#include "NumDays.h"

class NumDays;

using namespace std;

class TimeOff {
private:
    string name;
    int numberID;
    //create NumDay objects for TimeOff variables
    //since it will be automatically initialized to 0
    NumDays maxSickDays, sickTaken, maxVacation, vacTaken, maxUnpaid, unpaidTaken;
public:
    //default constructor
    TimeOff();
    
    //constructor
    TimeOff(string n, int id);
    
    //getter / accessor functions
    string getName() const;
    int getID() const;
    
    double getMaxSickDays();
    double getSickTaken();
    double getMaxVacation();
    double getVacTaken();
    double getMaxUnpaid();
    double getUnpaidTaken();
    
    //setter / mutator function
    void setName(string n);
    void setID(int id);
    void setMaxSickDays(double h);
    void setSickTaken(double h);
    void setMaxVacation(double h);
    void setVacTaken(double h);
    void setMaxUnpaid(double h);
    void setUnpaidTaken(double h);
};


#endif /* TIMEOFF_H */

