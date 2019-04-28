/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 27, 2019, 9:58 PM
 */

#include <iostream>
#include <cstdlib>
#include "Date.h"

using namespace std;
void birthdate(Date *);

int main(int argc, char** argv) {
    Date test1;
    Date *birthday = new Date;
    //Month, Day, Year
    Date test2(3, 3, 1999);
    birthdate(birthday);
    
    test1.style();
    test1.style2();
    test1.style3();
    cout << endl;
    test2.style();
    test2.style2();
    test2.style3();
    cout << "-------------------------- User's input -------------------------- " <<endl;
    birthday->style();
    birthday->style2();
    birthday->style3();
    
    delete birthday;
    return 0;
}

void birthdate(Date *b) {
    int temp;
    cout << "Enter the month: ";
    cin >> temp;
    b->setMonth(temp);
    cout << "Enter the day: ";
    cin >> temp;
    b->setDay(temp);
    cout << "Enter the year: ";
    cin >> temp;
    b->setYear(temp);
}