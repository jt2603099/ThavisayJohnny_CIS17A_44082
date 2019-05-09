/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 29, 2019, 6:00 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "Car.h"

using namespace std;

int main(int argc, char** argv) {
    //Create car object
    Car test1(2008, "Honda");
    
    //Display the car make and model
    cout << test1.getYear() << " " << test1.getMake() <<endl;
    //Start accelerating 5x
    for (int i = 0; i < 5; i++) {
        test1.accelerate();
        cout << "Running ... current speed: " << test1.getSpeed() <<endl;
    }
    
    cout <<endl;
    //Now brake 5x
    for (int i = 0; i < 5; i++) {
        test1.brake();
        cout << "Braking ... current speed: " << test1.getSpeed() <<endl;
    }
    
    //Exit program
    return 0;
}

