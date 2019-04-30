/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: jt2603099
 *
 * Created on April 29, 2019, 8:59 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    double radius, pi = 3.14159;
public:
    Circle(); //default constructor
    Circle(double); //constructor that takes radius as an argument
    //Accessors / getter functions
    double getRadius() const {
        return radius;
    }
    double getArea() const {
        return pi * radius * radius;
    }
    double getDiameter() const {
        return radius * 2;
    }
    double getCircumference() const {
        return 2 * pi * radius;
    }
    //Mutators / setter functions
    double setRadius(double);
};


#endif /* CIRCLE_H */

