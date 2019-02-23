/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on February 22, 2019, 5:53 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    //Declare variables
    const double YEN_PER_DOLLAR = 100;
    const double EUROS_PER_DOLLAR = 87.98;
    double dollars, yen, euros;
    
    cout << setprecision(2) << fixed;
    cout << "Enter dollar amount: ";
    cin >> dollars;
    
    yen = dollars * YEN_PER_DOLLAR;
    euros = dollars * EUROS_PER_DOLLAR;
    
    cout << "$" << dollars << " = " << yen << " Yen \n";
    cout << "$" << dollars << " = " << euros << " Euros \n\n";

    return 0;
}

