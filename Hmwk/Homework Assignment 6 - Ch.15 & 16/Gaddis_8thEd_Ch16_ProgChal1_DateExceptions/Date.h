/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: jt2603099
 *
 * Created on April 27, 2019, 10:04 PM
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month, day, year;
    static int numOfDays[12];
    string MONTH[12] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
public:
    //accessors / getter functions
    int getMonth() const {
        return month;
    }
    int getDay() const {
        return day;
    }
    int getYear() const {
        return year;
    }
    //mutators / setter functions
    Date(); //Constructor
    Date(int, int, int);
    int setMonth(int);
    int setDay(int);
    int setYear(int);
    
    //overloaded operators
    Date operator ++ ();
    Date operator ++ (int);
    Date operator -- ();
    Date operator -- (int);
    Date operator - (const Date &right);
    
    //outputs
    void style();
    void style2();
    void style3();
};



#endif /* DATE_H */

