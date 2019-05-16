/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductionWorker.h
 * Author: jt2603099
 *
 * Created on May 15, 2019, 3:36 PM
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include <string>
#include <iostream>

#include "Employee.h"

class ProductionWorker : public Employee {
private:
    int shift; //day = 1, night = 2
    double payRate;
public:
    //default constructor of base class
    ProductionWorker() : Employee() {
        shift = 1;
        payRate = 0.0;
    }
    
    //overloaded constructor / redefine base function
    ProductionWorker(string n, int num, int d, int m, int y, int s, double pR) : Employee(n, num, d, m, y) {
        if ((s != 1 && s != 2) || pR < 0) {
            cout << "Invalid input for shift and/or payrate!" <<endl;
            exit(EXIT_FAILURE);
        } else {
            shift = s;
            payRate = pR;
        }
    }
    
    //getter function / accessor function
    string getShift() const;
    double getPayRate() const;
    
    //setter / mutator function
    void setShift(int s);
    void setPayRate(double p);
            
};


#endif /* PRODUCTIONWORKER_H */

