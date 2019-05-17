/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jt2603099
 *
 * Created on May 15, 2019, 11:19 PM
 */

#include <iostream>
#include <cstdlib>

#include "Essay.h"

using namespace std;

int main(int argc, char** argv) {
    //Declare variables
    int temp;
    //create Essay object
    Essay test;
    
    cout << "Enter points for grammar 0-30: ";
    cin >> temp;
    test.setGrammar(temp);
    cout << "Enter points for spelling 0-20: ";
    cin >> temp;
    test.setSpelling(temp);
    cout << "Enter points for length 0-20: ";
    cin >> temp;
    test.setLength(temp);
    cout << "Enter points for content 0-30: ";
    cin >> temp;
    test.setContent(temp);
    
    cout << "The score is " << test.getScore() << ".";
    cout << "The letter grade is " << test.getLetterGrade() << ".";
    
    
    
    return 0;
}

