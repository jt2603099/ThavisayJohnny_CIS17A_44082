/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 10, 2019, 6:25 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "DayOfYear.h"

using namespace std;

int main(int argc, char** argv) {
    int input;
    
    cout << "Enter a number from 1-365" <<endl;
    cin >> input;
    
    DayOfYear test(input);
    test.print();
    
    ++test;
    test.print();
    
    test++;
    test.print();
    
    --test;
    test.print();
    
    test--;
    test.print();
    
    cout << "-----------------------" <<endl;
    
    DayOfYear test2("November", 29);
    test2.print();
    
    ++test2;
    test2.print();
    
    test2++;
    test2.print();
    
    --test2;
    test2.print();
    
    test2--;
    test2.print();
   
    //End the program
    return 0;
}

