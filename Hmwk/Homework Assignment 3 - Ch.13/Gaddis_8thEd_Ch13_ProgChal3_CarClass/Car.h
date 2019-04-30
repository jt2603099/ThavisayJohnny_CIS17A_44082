/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.h
 * Author: jt2603099
 *
 * Created on April 29, 2019, 6:00 PM
 */

#ifndef CAR_H
#define CAR_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    int yearModel, speed;
    string make;
public:
    //Constructor
    Car(int year, string m);
    
    //Getter / accessor functions
    int getYear() const {
        return yearModel;
    }
    
    int getSpeed() {
        return speed;
    }
    
    string getMake() const {
        return make;
    }
    
    //Setter / mutator functions
    void accelerate();
    void brake();
    
};


#endif /* CAR_H */

