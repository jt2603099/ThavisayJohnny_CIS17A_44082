/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 * Purpose: Histogram
 * Created on March 3, 2019, 2:31 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned char input1, input2, input3, input4;
    
    //Input or initialize values Here
    cout<<"Create a histogram chart."<<endl;
    cout<<"Input 4 digits as characters."<<endl;
    cin >> input1 >> input2 >> input3 >> input4;

    
    //Histogram Here
    cout << input4 << " ";
        if (isdigit(input4)) {
            for (int i = input4-48; i > 0; i--) {
                cout << "*";
            } 
        } else {
            cout << "?";
        } cout <<endl;
    cout << input3 << " ";
            if (isdigit(input3)) {
                for (int i = input3-48; i > 0; i--) {
                    cout << "*";
                } 
            } else {
                cout << "?";
            } cout <<endl; 
    cout << input2 << " ";
            if (isdigit(input2)) {
                for (int i = input2-48; i > 0; i--) {
                    cout << "*";
                } 
            } else {
                cout << "?";
            } cout <<endl;
    cout << input1 << " ";
            if (isdigit(input1)) {
                for (int i = input1-48; i > 0; i--) {
                    cout << "*";
                } 
            } else {
                cout << "?";
            } cout <<endl;         
    //Exit
    return 0;
}

