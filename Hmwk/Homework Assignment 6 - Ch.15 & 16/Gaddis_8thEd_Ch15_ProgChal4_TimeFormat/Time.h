/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: jt2603099
 *
 * Created on May 15, 2019, 9:48 PM
 */

#ifndef TIME_H
#define TIME_H

class Time {
protected:
    int hour, min, sec;
public:
    //default constructor
    Time();
    
    //constructor
    Time(int h, int m, int s);
    
    //Accessor / getter functions
    int getHour() const;
    int getMin() const;
    int getSec() const;
    
    //Mutator / setter function
    void setHour(int h);
    void setMin(int m);
    void setSec(int s);
};


#endif /* TIME_H */

