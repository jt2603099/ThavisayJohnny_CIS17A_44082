/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 23, 2019, 11:00 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
//Function prototype
float celsius(float f);

int main(int argc, char** argv) {
    //Declare variables
    float f;
    
    cout << "Enter a number to convert Fahrenheit to Celsius: ";
    cin >> f;
    cout << f << " degree Fahrenheit = " << setprecision(2) << fixed << celsius(f) << " degree Celsius" <<endl;
    cout << "Will now display Celsius Equivalent for Fahrenheit from 0 to 20." <<endl;
    //Formatting for the table
        cout << "Fahrenheit \t\t Celsius" <<endl;
    for (int i=0; i<21; i++) {
        cout << "    " << i << " \t\t\t " << celsius(i) <<endl;
    }
    return 0;
}

float celsius(float f) {
    float c = 0.0f;
    c = (5.0 / 9.0) * (f - 32);
    return c;
}