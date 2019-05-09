/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 9, 2019, 2:06 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "Numbers.h"

using namespace std;

int main(int argc, char** argv) {
    int input;
   
    cout << "Enter a number between 0-9999: ";
    cin >> input;
    
    //Create object with user's input as a parameter
    Numbers test(input);
    
    //Display the number in word form
    test.print();
    
    //End the program
    return 0;
}

