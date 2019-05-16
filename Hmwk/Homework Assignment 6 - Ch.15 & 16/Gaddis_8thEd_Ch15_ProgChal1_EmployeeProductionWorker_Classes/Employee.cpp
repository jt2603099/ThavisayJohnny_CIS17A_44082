/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.cpp
 * Author: jt2603099
 *
 * Created on May 15, 2019, 4:14 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>


#include "Employee.h"

using namespace std;

//Default constructor
Employee::Employee() {
    name = "";
    number = 0;
    day = 0;
    month = 0;
    year = 0;
}
//Constructor
Employee::Employee(string n, int num, int d, int m, int y) {
    name = n;
    number = num;
    //validate date
    if (d < 0 || d > 31 || m < 0 || m > 12 || y < 1900 || y > 2019) {
        cout << "Invalid hire rate!" <<endl;
        exit(EXIT_FAILURE);
    } else {
        day = d;
        month = m;
        year = y;
    }
}

//getter / accessor functions
string Employee::getName() const {
    return name;
}
int Employee::getNumber() const {
    return number;
}
string Employee::getHireDate() {
    hireDate = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    return hireDate;
}

//setter / mutator functions
void Employee::setName(string n) {
    name = n;
}
void Employee::setNumber(int num) {
    number = num;
}
void Employee::setHireDate(int d, int m, int y) {
    //validate date
    if (d < 0 || d > 31 || m < 0 || m > 12 || y < 1900 || y > 2019) {
        cout << "Invalid hire rate!" <<endl;
        exit(EXIT_FAILURE);
    } else {
        day = d;
        month = m;
        year = y;
    }
}

