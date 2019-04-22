/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on April 16, 2019, 7:13 PM
 * a) Using a byte variable, what is the largest factorial that can 
    be calculated.  A factorial is simply 

    n! = 1 * 2 * 3 * 4 ... * (n-2) * (n-1) * n

    For instance, 1! = 1,  2! = 2,  3! = 6,  4! = 24,  5! = 120 etc....

    b)  What would be the largest factorial using short, int, long, float, 
    double, etc...  Use all the primitive data types that you are familiar 
    with signed as well as unsigned.

    Note:  I want you to investigate this and the program you 
    turn in should just print "cout" the final results.  You don't know 
    how to capture errors yet so run each till it overflows then back off by 1.
    Don't need the program that tests for this.

 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int SIZE = 15;

void getFactorial(string name[], int byte[], unsigned long long int value[]);

int main(int argc, char** argv) {
    string DataTypes[SIZE] = {"short int", "unsigned short int", "unsigned int", "int", "long int", "unsigned long int", "long long int", "unsigned long long int",
                              "signed char", "unsigned char", "float", "double", "long double", "wchar_t", "wchar_t"};
    int DataBytes[SIZE] = {2, 2, 4, 4, 4, 4, 8, 8, 1, 1, 4, 8, 12, 2, 4};
    unsigned long long int Values[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    getFactorial(DataTypes, DataBytes, Values);
    
    /*for (int i = 0; i < SIZE; i++) {
        cout << Values[i] << " ";
    }*/
    
    return 0;
}

void getFactorial(string name[], int byte[], unsigned long long int value[]) {
    int f = 0;
    string biggestName;
    unsigned long long int factorial = 1,
                           biggestValue = 0;
    
    for (int i = 0; i < SIZE; i++) {
        f = byte[i];
            for (int k = 1; k <= f; k++) {
                factorial *= k;
            }
        value[i] = factorial;
        //Reset factorial value to calculate next byte in the array
        factorial = 1;
    }
    
    //Compare the value of each byte to determine highest value
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (value[i] < value[j]) {
                biggestName = name[j];
                biggestValue = value[j];
            }
        }
    }
    cout << "The Data Type with the largest value factorial is ";
    cout << biggestName << " with a value at " << biggestValue;
}
