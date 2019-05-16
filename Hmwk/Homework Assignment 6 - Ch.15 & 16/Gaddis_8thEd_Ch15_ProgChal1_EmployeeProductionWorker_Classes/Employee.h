/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: jt2603099
 *
 * Created on May 15, 2019, 3:36 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name, hireDate;
    int number, day, month, year;
public:
    //Default constructor
    Employee();
    //Constructor
    Employee(string n, int num, int d, int m, int y);
    
    //getter / accessor functions
    string getName() const;
    int getNumber() const;
    string getHireDate();
    
    //setter / mutator functions
    void setName(string n);
    void setNumber(int num);
    void setHireDate(int d, int m, int y);
    
};


#endif /* EMPLOYEE_H */

