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

#include "NumDays.h"

using namespace std;

int main(int argc, char** argv) {
    //2 test objects
    NumDays test1(8), test2(12);
    
    cout << "test1: " << test1.getDays() << " days & " << test1.getHours() << " hours." <<endl;
    cout << "test2: " << test2.getDays() << " days & " << test2.getHours() << " hours." <<endl;
    
    cout << test1 + test2 <<endl;
    cout << test2 - test2 <<endl;
    //overloaded ++ prefix operator
    ++test1;
    cout << "test1: " << test1.getDays() << " days & " << test1.getHours() << " hours." <<endl;
    
    //overloaded ++ postfix operator
    test1++;
    cout << "test1: " << test1.getDays() << " days & " << test1.getHours() << " hours." <<endl;
    
    //overloaded ++ prefix operator
    --test2;
    cout << "test2: " << test2.getDays() << " days & " << test2.getHours() << " hours." <<endl;
    
    //overloaded ++ postfix operator
    test2--;
    cout << "test2: " << test2.getDays() << " days & " << test2.getHours() << " hours." <<endl;
    
    //Exit program
    return 0;
}

