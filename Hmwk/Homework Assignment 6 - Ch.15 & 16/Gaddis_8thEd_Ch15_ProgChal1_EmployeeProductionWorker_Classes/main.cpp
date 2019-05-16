/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 14, 2019, 10:45 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

#include "ProductionWorker.h"

using namespace std;

int main(int argc, char** argv) {
    //create ProductionWorker object
    ProductionWorker test;
    
    test.setName("Johnny Billy");
    test.setNumber(001);
    test.setHireDate(2, 2, 2019);
    test.setShift(1);
    test.setPayRate(19.5);
    
    //display date
    cout << "Name: " << test.getName() <<endl;
    cout << "Number: " << test.getNumber() <<endl;
    cout << "Shift: " << test.getShift() <<endl;
    cout << "Hire Date: " << test.getHireDate() <<endl;
    cout << "Pay rate: " << test.getPayRate() <<endl;
    
    //exit program
    return 0;
}

