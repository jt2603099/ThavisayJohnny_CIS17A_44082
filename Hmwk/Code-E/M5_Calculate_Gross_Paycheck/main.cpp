/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 * Purpose: Overtime
 * Created on March 3, 2019, 12:07 PM
 * Develop an application that will determine the gross pay for employees. 
 * The company pays "straight-time" for the first 20 hours worked, time and a 
 * half for all hours worked in excess of 20 hours but less than 40 hours, and 
 * double time for any hours worked over 40 hours. Inputs to the program would 
 * be hours worked and rate of pay.  Output would be gross pay.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

float calc(float, unsigned short);
void grossPay(float);
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float payRate, totalPay;
    unsigned short hrsWrkd;
    
    //Input or initialize values Here
    cout<<"Paycheck Calculation."<<endl;
    cout<<"Input payRate in $'s/hour and hours worked"<<endl;
    cin>>payRate>>hrsWrkd;
    
    //Calculate Paycheck
    totalPay = calc(payRate, hrsWrkd);
    
    //Output the check
    grossPay(totalPay);
    
    //Exit
    return 0;
}

float calc(float payRate, unsigned short hours) {
    float totalPay;
    int excess, overtimeHours;
    
    if (hours <= 20) {
        totalPay = payRate * hours;
    } else if (hours < 40) {
        excess = ((hours - 20) * (payRate * 1.5));
        totalPay = ((payRate * 20) + excess);
    } else if (hours >= 40) {
        excess = payRate * 1.5 * 20;
        overtimeHours = hours - 40;
        totalPay = excess + (payRate * 20) + (overtimeHours * (2 * payRate));
    }
}

void grossPay(float totalPay) {
    cout << "$" << showpoint << fixed << setprecision(2) << totalPay <<endl;
}