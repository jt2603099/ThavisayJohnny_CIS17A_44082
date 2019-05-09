/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 29, 2019, 7:30 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Circle.h"

using namespace std;

void calcCircle(Circle *, double);

int main(int argc, char** argv) {
    Circle *u = new Circle;
    double radius;
    
    cout << "Find area, diameter, and circumference of a circle with user's radius." <<endl;
    cout << "What is the Radius?: ";
    cin >> radius;
    cout << "----------------------------------------------------------------------" <<endl;
    
    calcCircle(u, radius);
    
    delete u;
    //End program
    return 0;
}

void calcCircle(Circle *cir, double r) {
    cir->setRadius(r);
    cout << setprecision(2) << fixed << showpoint;
    cout << "Circle's Radius: " << r <<endl;
    cout << "Circle's Area: " << cir->getArea() <<endl;
    cout << "Circle's Diameter: " << cir->getDiameter() <<endl;
    cout << "Circle's Circumference: " << cir->getCircumference() <<endl;
}