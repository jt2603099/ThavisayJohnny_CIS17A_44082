/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.cpp
 * Author: jt2603099
 *
 * Created on April 29, 2019, 6:00 PM
 */

#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Car::Car(int year, string m) {
    yearModel = year;
    make = m;
    speed = 0;
}

void Car::accelerate() {
    speed += 5;
}

void Car::brake() {
    speed -= 5;
}