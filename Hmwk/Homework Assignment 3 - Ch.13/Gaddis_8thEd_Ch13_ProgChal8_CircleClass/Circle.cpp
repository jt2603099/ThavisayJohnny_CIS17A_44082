/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: jt2603099
 *
 * Created on April 29, 2019, 8:59 PM
 */

#include <iostream>
#include <cstdlib>

#include "Circle.h"

using namespace std;

//Default constructor
Circle::Circle() {
    radius = 0.0;
}

//Mutators / setter functions
double Circle::setRadius(double r) {
    radius = r;
}

