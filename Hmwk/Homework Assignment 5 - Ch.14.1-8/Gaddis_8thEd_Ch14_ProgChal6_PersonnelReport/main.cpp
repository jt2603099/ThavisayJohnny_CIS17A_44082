/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 11, 2019, 10:55 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "NumDays.h"
#include "TimeOff.h"

using namespace std;

const int vacHours = 12;
const int sickHours = 8;

int main(int argc, char** argv) {
    TimeOff test1;
    string name;
    int input;
    
    cout << "What is your name?: ";
    cin >> name;
    test1.setName(name);
    
    cout << "What is your id number?: ";
    cin >> input;
    test1.setID(input);
    
    cout << "Amount of months " << test1.getName() << "#" << test1.getID() << " has worked here?: ";
    cin >> input;
    
    test1.setMaxVacation(input * vacHours);
    test1.setMaxSickDays(input * sickHours);
    
    cout << "Employee " << test1.getName() << "#" << test1.getID();
    cout << " has " << test1.getMaxVacation() << " vacation days and ";
    cout << test1.getMaxSickDays() << " days of sick leave." <<endl;
    
    
    //Exit program
    return 0;
}

