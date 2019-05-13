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

int main(int argc, char** argv) {
    //2 test objects
    TimeOff test1;
    test1.setName("Johnny T");
    test1.setID(001);
    
    int input;
    
    cout << "Enter max sick days in hours! ";
    cin >> input;
    test1.setMaxSickDays(input);
    cout << "Enter sick days taken in hours! ";;
    cin >> input;
    test1.setSickTaken(input);
    cout << "Enter max vacation days in hours! ";
    cin >> input;
    test1.setMaxVacation(input);
    cout << "Enter vacation days taken in hours! ";
    cin >> input;
    test1.setVacTaken(input);
    cout << "Enter max unpaid days in hours! ";
    cin >> input;
    test1.setMaxUnpaid(input);
    cout << "Enter max unpaid taken days in hours! ";
    cin >> input;
    test1.setUnpaidTaken(input);
    
    //show the results
    cout << "Max Sick Days: " << test1.getMaxSickDays() <<endl;
    cout << "Max Sick Days Taken: " << test1.getSickTaken() <<endl;
    cout << "Max Vacation Days: " << test1.getMaxVacation() <<endl;
    cout << "Max Vacation Days Taken: " << test1.getMaxUnpaid() <<endl;
    cout << "Max Unpaid Vacation: " << test1.getMaxUnpaid() <<endl;
    cout << "Max Unpaid Leave: " << test1.getUnpaidTaken() <<endl;
    
    
    
    
    //Exit program
    return 0;
}

