/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GradedActivity.h
 * Author: jt2603099
 *
 * Created on May 15, 2019, 11:38 PM
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity {
protected:
    double score;
public:
    //Default constructor
    GradedActivity();
    
    //Constructor
    GradedActivity(double s);
    
    //mutator / setter function
    void setScore(double s);
    
    //accessor / getter function
    double getScore() const;
    
    char getLetterGrade() const;
};



#endif /* GRADEDACTIVITY_H */

