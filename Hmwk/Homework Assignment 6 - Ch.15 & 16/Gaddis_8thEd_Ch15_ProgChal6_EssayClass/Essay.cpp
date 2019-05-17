/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.cpp
 * Author: jt2603099
 *
 * Created on May 16, 2019, 6:12 PM
 */

#include <iostream>
#include <cstdlib>

#include "Essay.h"

using namespace std;

//getter / accesosr functions
    int Essay::getGrammar() const {
        return grammar;
    }
    int Essay::getSpelling() const {
        return spelling;
    }
    int Essay::getLength() const {
        return length;
    }
    int Essay::getContent() const {
        return content;
    }
   
    //setter / mutator function
    void Essay::setGrammar(int g) {
        while (g < 0 || g > GRAMMAR) {
            cout << "Enter again: ";
            cin >> g;
        }
        grammar = g;
        //update so it doesn't stay static
        GradedActivity::setScore(grammar + spelling + length + content);
    }
    void Essay::setSpelling(int s) {
        while (s < 0 || s > SPELLING) {
            cout << "Enter again: ";
            cin >> s;
        }
        spelling = s;
        //update so it doesn't stay static
        GradedActivity::setScore(grammar + spelling + length + content);
    }
    void Essay::setLength(int l) {
        while (l < 0 || l > LENGTH) {
            cout << "Enter again: ";
            cin >> l;
        }
        length = l;
        //update so it doesn't stay static
        GradedActivity::setScore(grammar + spelling + length + content);
    }
    void Essay::setContent(int c) {
        while (c < 0 || c > CONTENT) {
            cout << "Enter again: ";
            cin >> c;
        }
        content = c;
        //update so it doesn't stay static
        GradedActivity::setScore(grammar + spelling + length + content);
    }

