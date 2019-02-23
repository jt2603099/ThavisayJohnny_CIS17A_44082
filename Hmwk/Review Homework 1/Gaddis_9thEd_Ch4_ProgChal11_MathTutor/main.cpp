/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 22, 2019, 7:54 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    
    double A, B, C;
    int ans;
    
    unsigned seed = time(0);
    srand(seed);

    cout << "Hello, Welcome to Math Tutor, 1st Edition." << endl;
    cout << "I will display two random numbers, try and solve for the answer." << endl;

        A = 1 + rand() % 350;
        B = 1 + rand() % 350;
        C = A + B;

    cout << endl;
    cout << A << " + " << B << " = ?" << endl;
    cout << "Enter your answer!" <<endl;
        cin >> ans;
    
        if (ans == C) {
            cout << "Congratulations, you got it correct! The answer is " << C << "." <<endl;
        } else {
            cout << "Incorrect, the actual answer is " << C << "!" <<endl;
        }
    
    return 0;
}

