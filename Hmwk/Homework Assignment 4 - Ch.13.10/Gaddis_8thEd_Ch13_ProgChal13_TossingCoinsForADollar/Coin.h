/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coin.h
 * Author: jt2603099
 *
 * Created on May 4, 2019, 2:48 PM
 */

#ifndef COIN_H
#define COIN_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Coin {
private:
    string sideUp = "";
public:
    Coin(); //default constructor
    
    //Accessor / getter functions
    string getSideUp() const {
        return sideUp;
    }
    
    //Mutator / setter functions
    void toss();

};

#endif /* COIN_H */

