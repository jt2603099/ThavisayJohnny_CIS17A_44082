/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 30, 2019, 7:54 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip> //setprecision

#include "PayRoll.h"

using namespace std;

int main(int argc, char** argv) {
    //Declare variables
    //dynamically allocate an array for 7 objects(employees)
    PayRoll *employee = new PayRoll[7];
    
    //store data for each employee
    for (int i = 0; i < 7; i++) {
        cout << "Employee " << i + 1 << " hours: ";
        employee[i].setHours();
        cout << "Employee " << i + 1 << " pay rate: ";
        employee[i].setRate();
    }
    
    //display weekly pay for each employee
    for (int i = 0; i < 7; i++) {
        cout << fixed << setprecision(2);
        cout << "Employee " << i + 1 << " weekly pay: " << employee[i].getWeekly() <<endl;
    }
    
    cout << "Finished!" <<endl;
    
    //Exit program
    return 0;
}

