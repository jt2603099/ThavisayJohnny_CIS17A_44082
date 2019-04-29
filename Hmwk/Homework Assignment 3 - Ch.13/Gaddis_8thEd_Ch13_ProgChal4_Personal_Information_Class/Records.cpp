/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Records.cpp
 * Author: jt2603099
 * 
 * Created on April 28, 2019, 8:27 PM
 */

#include "Records.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
    
    Records::Records() {
        name = "N/A";
        address = "N/A";
        age = 0;
        phone = 0;
    }
    Records::Records(string n, string a, int life) { //Default Constructor
        name = n, address = a, age = life, phone = 0;
    } 
    Records::Records(string n, string a, int life, int p) {
        name = n, address = a, age = life, phone = p;
    }
    //mutators / setter functions
    void Records::setName(std::string n) {
        name = n;
    }
    void Records::setAddress(std::string a) {
        address = a;
    }
    void Records::setAge(int a) {
        age = a;
    }
    void Records::setPhone(int p) {
        phone = p;
    }
