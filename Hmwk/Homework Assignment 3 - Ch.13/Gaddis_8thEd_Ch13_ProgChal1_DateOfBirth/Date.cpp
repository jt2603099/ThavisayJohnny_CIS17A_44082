/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.cpp
 * Author: jt2603099
 *
 * Created on April 27, 2019, 11:58 PM
 */

#include <iostream>
#include <cstdlib>
#include "Date.h"

using namespace std;
    
     Date::Date() {
        month = 1, day = 1, year = 1900;
    }
     
    Date::Date(int m = 1, int d = 1, int y = 1900) { //Constructor
        month = m, day = d, year = y;
        if (month < 1 || month > 12) {
            cout << "Month can only be between 1-12!" <<endl;
            cout << "EXITING" <<endl;
            exit(EXIT_FAILURE);
        }
        if (day < 1 || day > 31) {
            cout << "Days can only be between 1-31!" <<endl;
            cout << "EXITING" <<endl;
            exit(EXIT_FAILURE);
        }
    }

    int Date::setMonth(int m) {
        if (m < 1 || m > 12) {
            cout << "Month can only be between 1-12!" <<endl;
            exit(EXIT_FAILURE);
        } else {
            month = m;
        }
    }
    
    int Date::setDay(int d) {
        if (d < 1 || d > 31) {
            cout << "Day can only be between 1-12!" <<endl;
            exit(EXIT_FAILURE);
        } else {
        day = d;
        }
    }
    
    int Date::setYear(int y) {
        year = y;
    }
    
    void Date::style() {
        cout << month << "/" << day << "/" << year <<endl;
    }
    void Date::style2() {
        cout << MONTH[month-1] << " ";
        cout << day << ", " << year <<endl;
    }
    void Date::style3() {
        cout << day << " " << MONTH[month-1];
        cout << " " << year <<endl;
    }