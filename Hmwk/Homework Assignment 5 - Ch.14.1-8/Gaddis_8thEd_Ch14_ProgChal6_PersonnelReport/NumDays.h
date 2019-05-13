/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumClass.h
 * Author: jt2603099
 *
 * Created on May 11, 2019, 11:00 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>

class NumDays {
private:
    double hours, days;
public:
    //Default constructor
    NumDays();
    
    //Constructor
    NumDays(double h);
    
    //Getter / accessor functions
    double getHours();
    double getDays();
    
    //Setter / mutator functions
    void setHours(double h);
    void setDays(double d);
    
    //overloaded + operator
    double operator + (const NumDays &right);
    
    //overloaded - operator
    double operator - (const NumDays &right);
    
    //overloaded prefix ++ operator
    NumDays operator ++ ();
    
    //overloaded postfix ++ operator
    NumDays operator ++ (int);
    
    //overloaded prefix -- operator
    NumDays operator -- ();
    
    //overloaded postfix -- operator
    NumDays operator -- (int);
};

#endif /* NUMCLASS_H */

