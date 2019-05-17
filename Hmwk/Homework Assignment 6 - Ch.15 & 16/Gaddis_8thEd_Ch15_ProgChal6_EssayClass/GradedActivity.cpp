/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GradedActivity.cpp
 * Author: jt2603099
 *
 * Created on May 15, 2019, 11:41 PM
 */

#include <iostream>
#include <cstdlib>

#include "GradedActivity.h"

//default constructor
GradedActivity::GradedActivity() {
    score = 0;
}

//accessor
double GradedActivity::getScore() const {
    return score;
}

//mutator
void GradedActivity::setScore(double s) {
    score = s;
}

char GradedActivity::getLetterGrade() const {
    char letterGrade;
    
    if (score > 89)
      letterGrade = 'A';
   else if (score > 79)
      letterGrade = 'B';
   else if (score > 69)
      letterGrade = 'C';
   else if (score > 59)
      letterGrade = 'D';
   else
      letterGrade = 'F';

   return letterGrade;
}

