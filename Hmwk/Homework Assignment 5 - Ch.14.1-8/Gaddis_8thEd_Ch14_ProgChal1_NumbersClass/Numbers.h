/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.h
 * Author: jt2603099
 *
 * Created on May 9, 2019, 2:07 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include <iostream>
#include <string>

using namespace std;

const int TENS = 8;

class Numbers {
private:
    int number;
    static string lessThan20[20];
    static string hundred;
    static string thousand;
    static string tens[TENS];
public:
    //Constructor
    Numbers(int);
    
    void print();
};



#endif /* NUMBERS_H */

