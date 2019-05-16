/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 15, 2019, 9:33 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "MilTime.h"

using namespace std;

int main(int argc, char** argv) {
    //Create MilTime object with parameters
    MilTime test(1220, 39);
    
    cout << "Military format: " << test.getHours() <<endl;
    cout << "Standard format: " << test.getStandHr() <<endl;
    
    test.setTime(999, 12);
    cout << "Military format: " << test.getHours() <<endl;
    cout << "Standard format: " << test.getStandHr() <<endl;
    
    //Exit program
    return 0;
}

