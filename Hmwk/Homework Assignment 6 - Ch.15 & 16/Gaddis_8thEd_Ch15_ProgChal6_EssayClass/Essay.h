/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.h
 * Author: jt2603099
 *
 * Created on May 15, 2019, 11:42 PM
 */

#ifndef ESSAY_H
#define ESSAY_H

#include <iostream>

#include "GradedActivity.h"

using namespace std;

const int GRAMMAR = 30;
const int SPELLING = 20;
const int LENGTH = 20;
const int CONTENT = 30;

class Essay : public GradedActivity {
private:
    double grammar, spelling, length, content;
public:
    //default constructor of base class
    Essay() : GradedActivity() {
        grammar = 0;
        spelling = 0;
        length = 0;
        content = 0;
    }
    
    //overloaded constructor of base class
    Essay(int g, int s, int l, int c) : GradedActivity(g+s+l+c) {
        grammar = g;
        spelling = s;
        length = l;
        content = c;
    }
    
    //getter / accesosr functions
    int getGrammar() const;
    int getSpelling() const;
    int getLength() const;
    int getContent() const;
    
    //setter / mutator function
    void setGrammar(int g);
    void setSpelling(int s);
    void setLength(int l);
    void setContent(int c);
};


#endif /* ESSAY_H */

