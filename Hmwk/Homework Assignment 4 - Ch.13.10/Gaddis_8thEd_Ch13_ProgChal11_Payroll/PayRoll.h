/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Payroll.h
 * Author: jt2603099
 *
 * Created on April 30, 2019, 7:54 PM
 */

#ifndef PAYROLL_H
#define PAYROLL_H

class PayRoll {
private:
    double payRate, weeklyPay;
    int hours;
public:
    PayRoll(); //Default constructor
        
    //Overloaded constructor with parameters
    PayRoll(int h, double rate);
    
    //Accessors / getter functions
    int getHours() const {
        return hours;
    }
    
    double getRate() const {
        return payRate;
    }
    
    double getWeekly() const {
        return weeklyPay;
    }
    
    //Mutators / setter functions
    int setHours();
    
    double setRate();
};









#endif

