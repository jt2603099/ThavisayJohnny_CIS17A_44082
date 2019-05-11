/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 10, 2019, 4:58 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "DayOfYear.h"

using namespace std;

int main(int argc, char** argv) {
    //Declare variables
    int input;
    
    cout << "Enter a day number between 1 & 365: ";
    cin >> input;
    
    //Create DayOfYear object with user's input as a parameter
    DayOfYear test(input);
    
    //Print the result
    test.print();

    return 0;
}

