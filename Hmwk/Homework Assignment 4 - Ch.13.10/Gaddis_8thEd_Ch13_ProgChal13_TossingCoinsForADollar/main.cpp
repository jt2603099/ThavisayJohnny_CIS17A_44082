/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 5, 2019, 9:13 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "Coin.h"

using namespace std;

int main(int argc, char** argv) {
    int heads = 0, tails = 0, i = 1;
    double balance = 0.0;
    
    cout << "Creating Coin object..." <<endl;
    Coin quarter, dime, nickel;
    cout << "Coin object quarter, dime, nickel completed!" <<endl;
    
    while (balance < 1.00) {
        quarter.toss();
        dime.toss();
        nickel.toss();
        
        cout << "--------------- Turn " << i << " ---------------" <<endl;
        cout << "Quarter: " << quarter.getSideUp() <<endl;
        cout << "Dime: " << dime.getSideUp() <<endl;
        cout << "Nickel: " << nickel.getSideUp() <<endl;
        //count the side
        if (quarter.getSideUp() == "HEADS")
            balance += 0.25;
        if (dime.getSideUp() == "HEADS")
            balance += 0.10;
        if (nickel.getSideUp() == "HEADS")
            balance += 0.05;
    }
    
    cout << "-----=-----Results-----=-----" <<endl;
    cout << fixed << setprecision(2);
    cout << "Balance: $" << balance <<endl;
    if (balance == 1.00)
        cout << "You won!" <<endl;
    else
        cout << "Sorry you lose!" <<endl;
    
    //End the program
    return 0;
}

