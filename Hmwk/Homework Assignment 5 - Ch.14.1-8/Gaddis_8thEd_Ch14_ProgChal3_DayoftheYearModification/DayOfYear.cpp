/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.cpp
 * Author: jt2603099
 *
 * Created on May 10, 2019, 5:03 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "DayOfYear.h"

using namespace std;

//Declare variables
string DayOfYear::months[12] = {"January", "February", "March", "April",
                            "May", "June", "July", "August",
                            "September", "October", "November", "December"};

int DayOfYear::numOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Constructor
DayOfYear::DayOfYear(int d) {
    while (d < 1 || d > 365) {
        cout << "Enter a valid day!" <<endl;
        cin >> d;
    }
    day = d;
}

//Overloaded Constructor
DayOfYear::DayOfYear(string m, int d) {
int counter;
    for (counter = 0; counter < 12; counter++) {
        if (m == months[counter]) {
            break;
        }
        if (counter == 11) {
            cout << "Month input error!" << endl;
            exit(0);
        }
    }
    if (d < 1 || d > numOfDays[counter]) {
        cout << m << " can not have " << d << " days!" <<endl;
        exit(0);
    }
    if (counter == 0) {
        day += d;
    } else {
        while (counter >= 0) {
            day += numOfDays[--counter];
        }
        day += d;
    }
}

//overload prefix ++
DayOfYear DayOfYear::operator++() {
    if (day == 365) {
        day = 1;
    } else {
        ++day;
    }
    return *this;
}

//overload postfix ++
DayOfYear DayOfYear::operator++(int) {
    if (day == 365) {
        day = 1;
    } else {
        day++;
    }
    return *this;
}

//overload prefix --
DayOfYear DayOfYear::operator--() {
   if (day == 1) {
       day = 365;
   } else {
       --day;
   }
   return *this;
}

//overload postfix --
DayOfYear DayOfYear::operator--(int) {
    if (day == 1) {
        day = 365;
    } else {
        day--;
    }
    return *this;
}
void DayOfYear::print() {
    for (int i = 0; i < 12; i++) {
        if (day <= numOfDays[i]) {
            break;
        } else {
            //Subtract full months from day until it's less than 28
            day -= numOfDays[i];
            //increment month after every month to determine month index
            month++;
        }
    }
    //Display the month and day
    cout << months[month] << " " << day <<endl;
}
