/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.h
 * Author: jt2603099
 *
 * Created on May 10, 2019, 5:03 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>
#include <iostream>

using namespace std;

class DayOfYear {
private:
    int day = 0, month = 0;
    static string months[12];
    static int numOfDays[12];
public:
    //constructor
    DayOfYear(int d);
    
    //overloaded constructor
    DayOfYear(string m, int d);
    
    //overload prefix ++
    DayOfYear operator++();
    
    //overload postfix ++
    DayOfYear operator++(int);
    
    //overload prefix --
    DayOfYear operator--();
    
    //overload postfix --
    DayOfYear operator--(int);
    
    
    void print();
};



#endif /* DAYOFYEAR_H */

