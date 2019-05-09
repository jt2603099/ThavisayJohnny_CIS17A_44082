/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 4, 2019, 2:48 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "Coin.h"

using namespace std;

int main(int argc, char** argv) {
    int heads = 0, tails = 0;
    
    cout << "Creating Coin object..." <<endl;
    Coin test;
    cout << "Coin object test completed!" <<endl;
    
    for (int i = 0;i < 20;i++) {
        test.toss();
        cout << "Turn " << i + 1 << ": " << test.getSideUp() <<endl;
        //count the side
        if (test.getSideUp() == "HEADS")
            heads++;
        else
            tails++;
    }
    
    cout << "Number of Heads: " << heads <<endl;
    cout << "Number of Tails: " << tails <<endl;
    
    //End the program
    return 0;
}

