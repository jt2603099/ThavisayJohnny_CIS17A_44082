/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coin.cpp
 * Author: jt2603099
 * 
 * Created on May 4, 2019, 2:48 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "Coin.h"

using namespace std;
        
Coin::Coin() {              //default constructor
    srand(time(0));
    
    if ((rand() % 2) == 0)
        sideUp = "HEADS";
    else
        sideUp = "TAILS";
}

void Coin::toss() {         //mutator
    if ((rand() % 2) == 0) 
        sideUp = "HEADS";
    else
        sideUp = "TAILS";
}