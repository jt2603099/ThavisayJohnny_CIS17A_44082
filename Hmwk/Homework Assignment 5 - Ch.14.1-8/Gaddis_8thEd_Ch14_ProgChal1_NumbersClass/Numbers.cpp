/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.cpp
 * Author: jt2603099
 *
 * Created on May 9, 2019, 2:15 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "Numbers.h"

using namespace std;

string Numbers::lessThan20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                                    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string Numbers::hundred = "hundred"; 
string Numbers::thousand = "thousand";
string Numbers::tens[TENS] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

Numbers::Numbers(int n) {
    if (n < 0) {
        cout << "No negative numbers!" <<endl;
        exit(EXIT_FAILURE);
    } else {
        number = n;
    }
}

void Numbers::print() {
    //Breaks the loop if value entered is 0
    if (number == 0) {
        cout << lessThan20[0] <<endl;
    }
    while (number > 19) {
        //Finding thousands place
        if (number / 1000 > 0) {
            cout << lessThan20[number/1000] << " " << thousand << " ";
            //Update number to the remaining digits from the thousands place
            number = number % 1000;
        } else if (number / 100 > 0) {
            cout << lessThan20[number/100] << " " << hundred << " ";
            //Update to tens & ones digit place
            number = number % 100;
          //Check if number is 20 or greater
        } else if (number >= 20) {
            //twenty = 0 in tens index
            cout << tens[(number/10) - 2] << " ";
            //Update number to ones digit(if possible)
            number = number % 10;
            break;
        } 
    }
    if (number > 0) {
        cout << lessThan20[number] << " ";
    }
}

