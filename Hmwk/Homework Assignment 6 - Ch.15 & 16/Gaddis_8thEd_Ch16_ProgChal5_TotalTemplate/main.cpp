/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 16, 2019, 9:04 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip> //setprecision

using namespace std;

//function class prototype
template <class T>
T total(int numberOfValues);

int main(int argc, char** argv) {
    
    //3 ints
    cout << "Total: " << total<int>(3) <<endl;
    
    //4 char
    cout << "Total: " << total<float>(4) <<endl;
    
    //5 double
    cout << fixed << setprecision(2);
    cout << "Total: " << total<double>(5) <<endl;
    
    //End program
    return 0;
}

//total function class definition
template <class T>
T total(int numberOfValues) {
    T sum = 0, value;
    
    while (numberOfValues > 0) {
        cin >> value;
        sum += value;
        //Decrement counter
        numberOfValues--;
    }
    return sum;
}